use dirs::home_dir;

const YIG_CONFIG_FILE: &str = "yig.toml";
const YIG_CONFIG_MSG_HEADER: &str = "YIG V2 CONFIG >>";
const YIG_ARCHIVE_MSG_HEADER: &str = "YIG V2 ARCHIVE >>";
const YIG_DEF_ARCHIVE_PATH: &str = "/.yig/archive/";

pub fn get_config_dir() -> String {
    let home = home_dir().unwrap();
    let yig_config_path = format!("{}/.yig/", home.display());
    yig_config_path
}

pub mod config {
    use std::path::Path;
    use std::fs::File;

    use super::YIG_CONFIG_FILE;
    use super::YIG_CONFIG_MSG_HEADER;
    use super::get_config_dir;

    pub fn init() {
        let yig_config_dir = get_config_dir();
        let yig_config_path = Path::new(&yig_config_dir);

        if yig_config_path.exists() {
            println!("{} YIG config directory already exists at:\n    {}", YIG_CONFIG_MSG_HEADER, yig_config_path.display());
        } else {
            std::fs::create_dir_all(yig_config_path).unwrap();
        }
        let yig_config_file = format!("{}/{}", yig_config_path.display(), YIG_CONFIG_FILE);

        if Path::new(&yig_config_file).exists() {
            println!("{} Config file already exists at:\n    {}", YIG_CONFIG_MSG_HEADER ,yig_config_file);
            return;
        }

        File::create(Path::new(&yig_config_file)).expect("YIG config file creation failed.");

        let yig_config =
        r#"[yig]
msg_header = "YIG  >>"
archive_path = "/.yig/archive/"
editor = "none"
custom_commands = "commands.toml"
"#;
        std::fs::write(yig_config_file, yig_config).expect("YIG config file write failed.");
        
    }
}

pub mod archive {
    use dirs::home_dir;
    use std::fs::{File, copy};
    use std::path;
    use std::env::current_dir;
    use super::YIG_DEF_ARCHIVE_PATH;
    use super::YIG_ARCHIVE_MSG_HEADER;

    fn get_dir_path(filename : &str) -> String {

        let mut filepath = String::from(home_dir().unwrap().to_str().unwrap());
        filepath.push_str(YIG_DEF_ARCHIVE_PATH);
        filepath.push_str(filename);

        filepath
    }

    pub fn init() {
        let archive_dir = format!("{}/{}", home_dir().unwrap().to_str().unwrap(), YIG_DEF_ARCHIVE_PATH);
        let archive_path = path::Path::new(&archive_dir);

        if archive_path.exists() {
            println!("{} Archive directory already exists at:\n    {}", YIG_ARCHIVE_MSG_HEADER, archive_path.display());
        } else {
            std::fs::create_dir_all(archive_path).unwrap();
        }
    }

    pub fn save(filename: String) {
        let yig_save_path = get_dir_path(filename.as_str());
        let filepath = path::Path::new(&yig_save_path); 
        println!("Saved to : {:?} ", filepath);
        File::create(filepath).expect("File creation failed.");
        copy( &filename, filepath).expect("Copy failed.");  
    }

    pub fn load(filename: String) {
        let yig_saved_file = get_dir_path(filename.as_str());
        let filepath = path::Path::new(&yig_saved_file); 
        if filepath.is_file() {
            let new_file = format!(
                "{}/{}",
                current_dir()
                    .unwrap()
                    .into_os_string()
                    .into_string()
                    .unwrap(),
                    &filename.as_str()
            );
            println!("{} File found in archive. Copying file.", YIG_ARCHIVE_MSG_HEADER);
            File::create(&filepath).expect("File creation failed.");
            copy(yig_saved_file, new_file).expect("Copy failed.");    
        } else {
            println!("{} File not found in archive.", YIG_ARCHIVE_MSG_HEADER);
        }
    }

    pub fn show_archive_contents()
    {
        let archive_dir = format!("{}/{}/", home_dir().unwrap().to_str().unwrap(), YIG_DEF_ARCHIVE_PATH);
        let paths = std::fs::read_dir(archive_dir).unwrap();

        println!("{} Archive contents are:", YIG_ARCHIVE_MSG_HEADER);
        for (n, i) in paths.enumerate() {
            println!(">> File {} :    {}", n + 1, i.unwrap().file_name().into_string().unwrap());
        }
    }
}

pub mod commands {
    use std::process::Command;
    use std::fs::File;
    use std::io;
    use std::path::Path;
    use toml::{self, Table};
    const YIG_COMMANDS_MSG_HEADER: &str = "YIG V2 COMMANDS >>";
    use super::get_config_dir;

    pub fn init() {
        let yig_config_dir = get_config_dir();
        let yig_config_path = Path::new(&yig_config_dir);
        let yig_commands_file = format!("{}/commands.toml", yig_config_path.display());

        if Path::new(&yig_commands_file).exists() {
            println!("{} Commands file already exists at:\n    {}", YIG_COMMANDS_MSG_HEADER ,yig_commands_file);
            return;
        }

        File::create(Path::new(&yig_commands_file)).expect("YIG commands file creation failed.");

        let yig_commands = 
r#"[commands]
"hello" = "echo 'Hello, YIG!'"
"#;
        std::fs::write(yig_commands_file, yig_commands).expect("YIG commands file write failed.");
    }

    pub fn call(command_name: &str) {
        let commands_data = get_commands();
        let commands_table = commands_data.get("commands").unwrap().as_table().unwrap();

        let command = commands_table.get(command_name);
        match command {
            Some(cmd) => {
                println!("{} Running command: {}", YIG_COMMANDS_MSG_HEADER, cmd.as_str().unwrap());
                let mut cmd_str = cmd.as_str()
                    .unwrap()
                    .split_whitespace()
                    .collect::<Vec<&str>>(); 
                let name = cmd_str.remove(0);
                let args = cmd_str;
                run_cli_command(name, &args);
            },
            None => println!("{} Command \'{}\' not found in commands file.", YIG_COMMANDS_MSG_HEADER, command_name),
        };
    }

    pub fn show() {
        let commands: toml::Value = get_commands();
        let command = match commands.get("commands"){
            Some(c) => c,
            None => {
                println!("{} No commands found in commands file.", YIG_COMMANDS_MSG_HEADER);
                return;
            }
        };

        println!("{} Available commands:\n", YIG_COMMANDS_MSG_HEADER);
        for (name,cmd) in command.as_table().unwrap() {
            println!("    {} => {}", name, cmd.as_str().unwrap());
        } 
    }

    fn get_commands_filename() -> String {
        let yig_config_dir = get_config_dir();
        let yig_commands_file = format!("{}/commands.toml", yig_config_dir);
        yig_commands_file
    }

    fn get_commands_string() -> String {
        let yig_commands_file = get_commands_filename();
        let commands = std::fs::read_to_string(yig_commands_file).expect("YIG commands file read failed.");
        commands
    }

    fn get_commands() -> toml::Value {
        let commands = get_commands_string();
        let commands_values: toml::Value = toml::from_str(&commands).expect("YIG commands file parse failed.");

        commands_values
    }

    pub fn add() {

        let contents = get_commands_string();

        println!("{} Enter the new command name for you to call: ", YIG_COMMANDS_MSG_HEADER);
        let mut new_user_cmd = String::new();
        let _ = io::stdin().read_line(&mut new_user_cmd).unwrap();

        println!("{} Enter the command to run: ", YIG_COMMANDS_MSG_HEADER);
        let mut new_exec_cmd = String::new();
        let _ = io::stdin().read_line(&mut new_exec_cmd).unwrap();

        let mut main_table = contents.parse::<Table>().unwrap();
        let commands_table = main_table["commands"].as_table_mut().unwrap();
        commands_table.insert(new_user_cmd.trim().to_string(), toml::Value::String(new_exec_cmd.trim().to_string())); 
        println!("{:?}", commands_table);
        

        println!("{} Writing new command to file.", YIG_COMMANDS_MSG_HEADER);
        let yig_commands_filename = get_commands_filename();
        println!("{} path: {}", YIG_COMMANDS_MSG_HEADER, yig_commands_filename);
        let new_contents = toml::to_string(&main_table).unwrap();
        std::fs::write(yig_commands_filename, new_contents).expect("YIG commands file write failed.");
    }

    fn run_cli_command(command: &str, args: &[&str]) {
        Command::new(command)
            .args(args)
            .spawn()
            .unwrap()
            .wait()
            .expect("Failed");
    }

}