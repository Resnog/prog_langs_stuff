-- This script will take a file of text and wrap it to a specified width.
import System.IO
import Control.Monad
import Data.List.Split
import Data.List
import Data.Maybe (fromMaybe)
import System.Console.GetOpt
import System.Environment

-- Command line argument handling

data Flag = Version
          | Help
          | MarginWidth Int
          | File String deriving (Show)

data CmdInput = CmdInput { marginWidth :: Int
                         , inputFile :: String
                         } deriving (Show)

isMarginWidth :: Flag -> Bool
isMarginWidth (MarginWidth _) = True
isMarginWidth _ = False

getMarginWidth :: Flag -> Int
getMarginWidth (MarginWidth m) = m
getMarginWidth _ = 80

isFile :: Flag -> Bool
isFile (File _) = True
isFile _ = False

getFileString :: Flag -> String
getFileString (File s) = s

options :: [OptDescr Flag]
options = [ Option ['v'] ["version"] (NoArg Version) "Print version information"
          , Option ['h'] ["help"] (NoArg Help) "Print help information"
          , Option ['m'] ["margin"] (ReqArg (MarginWidth . read) "WIDTH") "Set the margin width"
          , Option ['f'] ["file"] (ReqArg File "FILE") "Set the input file"
          ]

-- inp,outp :: Maybe String -> Flag
-- outp = OutputFile . fromMaybe "stdout"
-- inp  = InputFile  . fromMaybe "stdin"
   
compilerOpts :: [String] -> IO ([Flag], [String])
compilerOpts argv = 
    case getOpt Permute options argv of
        (o,n,[]  ) -> return (o,n)
        (_,_,errs) -> ioError (userError (concat errs ++ usageInfo header options))
    where header = "Usage: textWraper [OPTION...] args..."

-- Text formatting functions 

lineWidth = 50

type FileContents = [Paragraph]
type Paragraph = [Line]
type WordList = [String]
type LineProgress = (WordList, Line)
type Line = String

testString = "This is a new buffet in the downtown area\nand another thing my dear puddle of sweat,\nI like pancakes hot and covered with honey.\n\nTommy had a nice sandwich made\nby his sister Tiffany\n"


separateFileParagraphs :: String -> [String]
separateFileParagraphs file = splitOn "\n\n" file

separateFileLines :: [String] -> FileContents
separateFileLines fileParagraphs = map (words) (fileParagraphs)

getFileContents :: String -> FileContents
getFileContents file = separateFileLines (separateFileParagraphs file)

createNewLine :: WordList -> Line -> Int -> LineProgress
createNewLine [] line _ = ([], line)
createNewLine wordList line lineWidth = if length line + length nextWord > (lineWidth - 1)
                                        then (wordList, tail line)
                                        else createNewLine newWordList newLine lineWidth
    where nextWord = head wordList
          newWordList = tail wordList
          newLine = line ++ " " ++ nextWord

createNewParagraph :: WordList -> Paragraph -> Int -> Paragraph
createNewParagraph wordList paragraph lineWidth = if null wordList
                                         then paragraph
                                         else createNewParagraph newWordList newParagraph lineWidth
    where (newWordList, newLine) = createNewLine wordList [] lineWidth
          newParagraph = paragraph ++ [newLine]

createNewFileContents :: FileContents -> FileContents -> Int -> FileContents
createNewFileContents fileContents newFileContents lineWidth = if null fileContents
                                                         then newFileContents
                                                         else createNewFileContents updatedFileContents updatedNewFileContents lineWidth
    where newParagraphContents = createNewParagraph (head fileContents) [] lineWidth
          updatedNewFileContents = newFileContents ++ [newParagraphContents]
          updatedFileContents = tail fileContents

convertFileContentsToString :: FileContents -> String -> String
convertFileContentsToString fileContents newStr = if null fileContents
                                                   then newStr
                                                   else convertFileContentsToString restOfFile strChain
    where jointParagraph = unlines (head fileContents)
          strChain = newStr ++ jointParagraph ++ "\n"
          restOfFile = tail fileContents

test = createNewFileContents (getFileContents testString) []

main = do 
    -- Read the file contents
    args <- getArgs
    (flags, files) <- compilerOpts args
    let margin = getMarginWidth (head (filter isMarginWidth flags))
    let filename = getFileString (head (filter isFile flags))
    file <- readFile filename
    let newFileContents =  createNewFileContents (getFileContents file) [] margin
    let newFileStr = convertFileContentsToString newFileContents []
    when (length newFileStr > 0) $
        writeFile filename newFileStr
    --print margin
    --print file
    --print newFileStr
    --print newFileStr
    --print newFileStr
    -- Wrap the text
    -- Write the wrapped text to a new file
    -- Close the file