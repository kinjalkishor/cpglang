# cpglang
cpglang Programming Language  
cpglang is mostly like C & C++ with syntax like Pascal and Go. (C: C/C++/dlang, P: Pascal, G: Golang)  
Features and Goals of cpglang -
- Fastest compile times. Using clang & dmd as backend.
- Easier to read, understand, parse syntax.
- Takes features from mainly C/C++, dlang, rustlang.
- No GC (Garbage Collector).
- Add long time demanded features to C/C++ like Modules, UFCS, SIMD.
- Tries to solve ambiguity problems in parsing C/C++.
- A subset of language (mainly without pointers) to be used as embedded scripting language.
- Make C/C++ safer.
- Note: No borrow checker, lifetimes, single ownership, type checker. Allows self-referential data structures.
- No multiple inheritance.

# Project Status
Use vsix file locally with vscode for keyword syntax highlighting. (Still under development).  
copy "cpglang.tmLanguage.json" to "%userprofile%\.vscode\extensions\akin.cpglang-0.0.1\syntaxes", to replace with current syntax definition file.  
Compiler development has not started. Working on syntax currently.  
