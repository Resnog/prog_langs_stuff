mod yig;

use clap::Parser;
use std::fs::File;

const YIG_MSG_HEADER: &str = "YIG >>";

#[derive(Parser)]
// Yig CLI commands
struct Cmds {
    /// Copy file to the save directory
    #[arg(short, long)]
    save: Option<String>,
    /// Copy file from the save directory
    #[arg(short, long)]
    load: Option<String>,
    /// Show saved files
    #[arg(long)]
    archived: bool,
    /// Init the YIG configuration
    #[arg(long)]
    init: bool,
    /// Custom user commands, enter 'list' to show available commands
    #[arg(short, long)]
    command: Option<String>,
}

fn main() {
    
    let inputs = Cmds::parse();


    if inputs.init {
        yig::config::init();
        yig::archive::init();
        yig::commands::init();
    }

    if inputs.save.is_some() {
        let filename = inputs.save.unwrap();
        // Check if the file exists
        if let Err(_) = File::open(&filename) {
            println!("{} Specified file to save not found in current directory.", YIG_MSG_HEADER);
            return;
        }
        yig::archive::save(filename);   
    }

    if inputs.load.is_some(){
        let filename = inputs.load.unwrap();
        yig::archive::load(filename);
    }

    if inputs.archived {
        yig::archive::show_archive_contents();
    }

    if inputs.command.is_some() {
        let command = inputs.command.unwrap();
            if command == "list"{
                yig::commands::show();
                return;
            } else if command == "add"{
                yig::commands::add();
            } else {
                yig::commands::call(&command);
            }
    }
}
