This project has been created as part of the 42 curriculum by abchtaib

Desciption :

    This project is about implementing a function called get next line that read from a file and return with a buffer size that can be adjusted during the compilation , this function in every call should return  first line from what was read ,in second call return the second line and so on ,until it reach the end of file EOF and return NULL.

Instructions :

    To make this function able to preserve the ramainder after the new line was returned ,its a mandatory to use a new type called static variable, so i go and make some research about this concept i understand how it work and where it's stored, this variable is initialize only one time which is on start of the program after the first initialize it keep it value even after the function return.

Resources :

    first resource of course is wikipedia, rabbit , grok ai and youtube.

Details about algorithme i use:

    i spend about 3 days reading the subject and trying to find a good logique that can solve this problem ,first problem that i face after writing the code is memory leak , befor that the logique that i found is perfect for me to use is ,
    reading from the file with BUFFER size bytes and put all what was read in a pointer who is already pointe to the stack in a memory of size BUFFER SIZE + 1 beacuse i want to put the null terminator at the end after reading i put the null termintor and use function strjoin to join the buffer that was allocated with the static which is in first calll initialize ponting to null , after joining i check if the is a new line with function strchr this function take as a parameters string and the characters to look inside the string if it's included or not if not it return 0 and keep reading in the same logique untile the strchr return a non zero value which mean that she found a new line , now the loop stop and next is to use a fuction which seperate the first line and return it and free the block in the memroy that was allocated in the first , if read return -1 the fucntion free al the previous allocation and return null.