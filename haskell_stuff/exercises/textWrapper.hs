-- This script will take a file of text and wrap it to a specified width.
import System.IO
import Control.Monad
import Data.List.Split

type FileContents = [Paragraph]
type Paragraph = [Line]
type Line = String

testString = "this is a new line\nand another\nI like pancakes\n\nTommy had a nice sandwich made\nby his sister Tiffany\n"

separateFileParagraphs :: String -> [String]
separateFileParagraphs file = splitOn "\n\n" file

separateFileLines :: [String] -> FileContents
separateFileLines fileParagraphs = map (splitOn "\n") (fileParagraphs)

getFileContents :: String -> FileContents
getFileContents file = separateFileLines (separateFileParagraphs file)

--test = getFileContents testString

main :: IO ()
main = do 
    -- Read the file contents
    file <- readFile "exercises/testing_files/example.txt"
    let fileContents = getFileContents file
    print fileContents
    -- Wrap the text
    -- Write the wrapped text to a new file
    -- Close the file