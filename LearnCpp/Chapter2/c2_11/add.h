// We really should have a header guard here, but will omit it for simplicity (we'll cover header guards in the next lesson)

// This is the content of the .h file, which is where the declarations go
int add(int x, int y); // function prototype for add.h -- don't forget the semicolon!

//Avoid #including .cpp files.
//Do not put function and variable definitions in your header files (for now).
//Defining either of these in a header file will likely result in a violation of 
//the one-definition rule (ODR) if that header is then #included into more than 
//one source (.cpp) file.