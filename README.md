# Snipper
 >A Command Line Interface to store, and organize code snippets based on programming language

## :memo: Usage
### :accessibility: Initialization
   To initialize the application, you must first specify a directory to save the snippets using:
   ```
snipper -directory <path/to/the/directory>
```
Example:
```
snipper -directory ../
```
The *Snippets* :file_folder: directory will be created at this location, which will contain all the organized code snippets.

### :white_check_mark: Creating a snippet
The tool may now be used by calling:
```
snipper <input file> <output name>
```
For example, if you're within a project folder located at *Documents/myProject/*, you can open a terminal, 
and run 
```
snipper main.cpp newSortIdea
```
Which will create a Snippet of this file, located at *the/path/you/chose/Snippets/C & C++/**newSortIdea.cpp***

>The `<input file>` must be referenced with its file extension. `<output name>` does not require a file extension, it will be the same as the input file type



### :information_source: General Info
Most common languages are supported, and will be auto-sorted upon creating a snippet.
the user's saved directory is stored in *$HOMEDIRECTORY/**./snipper_config***

## :gear: Installation

### Build from source using cmake:
  - **clone this repository**
       ```
      git clone https://github.com/phoenixjmh/snipper
      cd snipper
       ```
  - **Create build directory**
     
       ```
      mkdir build
      cd build
     ```

  - **Generate Cmake project**
       ```
       cmake ..
       ```
  -  **Build**
       ```
       cmake --build . --config Release
        ```
  - 
      **Install for system-wide usage**
    - Linux: `cmake --install .`
    - Windows: Add the folder containing the built *snipper.exe* to system environment variables as a new entry under PATH
    
*** 

   






