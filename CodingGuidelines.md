# Coding Guidelines and Standards
## Readability
- Variable and Function names need to make sense in the given context
- Code should be consistent
## Naming Conventions
- Single word variables should be in all lowercase
- Multi-word variables and functions should be in camel case
- Any private variables should begin with "m_"
## Documentation
- Be sure to leave comments for blocks of code or variables that may be more confusing
## Clang
- Clang must be installed on your system, steps to download are below:
- MacOS: 
- Run: /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
- Run: brew install clang-format
- Windows:
- Run: choco install llvm
## Testing
- Use the unit test to make sure that the program still works as intended
- Leave comments when merging so it is clear what has been altered
