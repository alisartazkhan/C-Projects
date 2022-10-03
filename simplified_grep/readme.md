# Project Description
#### This program will be a simplified version of the grep command that can be found on many UNIX systems, including lectura. The grep command can be used for searching for strings and patterns from standard input. Your program shouldfunction similarly, but it does not have to support as many arguments and features compared to the regular command.
#### This program should expect between 0 and 3 flag arguments, and one additional argument which specifies
what to search for. The program should support these three flag arguments in any position on the command
line:
* -o Only print the exact part(s) of each line that matches the search, not the entire line. The default
behavior of sgrep will be to print the whole line if a match is found.
* -i Use a case-insensitive search. The default behavior will be to search case-sensitive.
* -e Search using a pattern specification. The default behavior will be to search for the exact searchstring provided.
#### The other command-line argument will be some sequence of ascii-characters that represent what to search for.The search term can either function in a literal search (search of the exact string the user provides) or, with the-e flag, the user can give a pattern (one search term that can match multiple strings). More information about these patterns will be shown later in the specification. The program should support the arguments beingspecified in any order.
#### The search will act on whatever is “fed” to the program via standard input, and should continue to search until EOF is reached. The search results should be printed to standard output.

#### If you use the -e option, this allows the user to specify a search pattern rather than just a search word. The search pattern supports regular ascii characters, but it treats two particular characters in a special way:periods ( . ) and hashes ( # ). A period is a placeholder for any character. Thus, for example, the search term "c.t" would match wordssuch as "cat", "cut", and "cot". A hash matches one or more characters in that particular position. Thus, the search search pattern "c#t" would match words such as "cat", "cut", and "cot" but also should match strings such as "crest" and "crop or not". 
