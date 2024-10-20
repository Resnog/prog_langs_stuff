import Data.Maybe (fromMaybe)
import System.Console.GetOpt
import System.Environment

data Flag = Version
          | Help
          | MarginWidth Int
          | InputFile String
          | OutputFile String deriving (Show)



options :: [OptDescr Flag]
options = [ Option ['v'] ["version"] (NoArg Version) "Print version information"
          , Option ['h'] ["help"] (NoArg Help) "Print help information"
          , Option ['m'] ["margin"] (ReqArg (MarginWidth . read) "WIDTH") "Set the margin width"
          , Option ['i'] ["input"] (ReqArg InputFile "FILE") "Set the input file"
          , Option ['o'] ["output"] (ReqArg OutputFile "FILE") "Set the output file"
          ]

inp,outp :: Maybe String -> Flag
outp = OutputFile . fromMaybe "stdout"
inp  = InputFile  . fromMaybe "stdin"
   
compilerOpts :: [String] -> IO ([Flag], [String])
compilerOpts argv = 
    case getOpt Permute options argv of
        (o,n,[]  ) -> return (o,n)
        (_,_,errs) -> ioError (userError (concat errs ++ usageInfo header options))
    where header = "Usage: ic [OPTION...] files..."

-- The following code takes the command line arguments and prints them out
main :: IO ()
main = do
    args <- getArgs
    (flags, files) <- compilerOpts args
    print args
    print flags
    print files

