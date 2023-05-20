# Welcome to the Devoteam robot controller!
A CLI app for making your new robot move to your will.  
### Build and Run
To use the app, you first have to clone or download this repository to your machine.  
To compile it, execute Maven package command at the project's root directory:
``` Bash
$ mvn package
```
An executable .jar file will be created at the project's target directory.  
To run the app, execute the following command at the directory where the .jar is located:
``` Bash
$ java -jar robot-1.jar
```
### Testing
To run the tests, execute Maven's test command at the project's root directory:
``` Bash
$ mvn clean test
```
