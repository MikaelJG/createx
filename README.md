
![Logo](https://github.com/MikaelJG/noti/blob/master/assets/.png)

Createx is a CLI tool to create .tex files. It is the fastest book maker for lazy researchers.

Createx works in harmony with [Textract](https://github.com/createx) and [Noti](https://github.com/noti),
my note parser/editor CLI tool.

## Installation

In your home directory, create or update your .bashrc file.
```bash
$ cd # move to home
$ vim .bashrc # edit your .bashrc file
$ alias createx="~/path/to/.sh" # write an alias to createx.sh

# for example
  alias noti="~/code/
```
Using zsh? Update your .zshrc file.
```bash
$ cd # move to home
$ vim .zshrc # edit your zshrc file 

# for example
  alias noti="~/code/createx/createx.sh
```
## Usage 

Textract extracts verbatim examples and creates an example directory (output) for them.
```bash
$ ./createx file-to-extract extension-for-the-ex-files

# for example
$ ./createx ruby.tex rb
```
Noti-light finds the new extracted files and prints them (with cat).
```bash
$ ./createx file-to-extract extension-for-the-ex-files

# for example
$ ./createx ruby.tex rb
```

## Demo

To come.

