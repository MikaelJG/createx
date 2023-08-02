#!/bin/bash

if [ -z "$1" ]; then
    ARGS=("--help")
else
    ARGS=("$@")

    # count the array
    # args_length=${#ARGS[@]}
fi

files_for_tex_file=()

# Function to find .tex files_for_tex_file recursively
recursively_search_files(){
    dir="$1"
    ext="$2"

    # Loop through all files_for_tex_file and directories in the current directory
    for file in "$dir"/*; do
        if [[ -f "$file" && "$file" == *."$ext" ]]; then
            filename=$(basename ${file})
            echo "${dir}/${filename},file" >> sections.csv 

            # If the file is a .tex file, add it to the array
            files_for_tex_file+=("$file")

        elif [[ -d "$file" ]]; then

            section=$(basename ${file})
            clean_section_name=$(echo "$section" | sed 's/_/-/g')

            echo "${clean_section_name},directory" >> sections.csv

            # If the file is a directory, recursively call the function
            recursively_search_files "$file" "$ext"
        fi
    done
    echo "Recursion done."
}

create_tex_file() {

    date=$(date +"%m-%d-%H:%M")
    dirname="$1"
    title=$(echo "$dirname" | sed 's/_/-/g')
    tex_filename=${dirname}_${date}.tex

    touch "$tex_filename"
    echo "${tex_filename} file created."

    echo "
\documentclass[openany]{report}
\usepackage[margin=1.2in]{geometry}
\usepackage{graphicx}
\usepackage{parskip}
\usepackage{fancyhdr}

\pagestyle{fancy}
\fancyhf{}                      % Clear all header and footer fields
\fancyhead[R]{\leftmark}        % Display chapter name at the top right corner

\title{${title} Workbook}
\author{Mikael J. Gonsalves}
\date{\today}
\begin{document}
\maketitle
\tableofcontents

\chapter{${title}}
" > "$tex_filename"

    
    while IFS= read -r line; do
        IFS=',' read -r name _type <<< "$line"
        
        if [[ "$_type" == "directory" ]]; then

            echo "\section{${name}}" >> "$tex_filename"
            echo " " >> "$tex_filename"

            echo " "
            echo "Section ${name} created."
            echo " "

        else
            subsection_name=$(basename $name)
            clean_subsection_name=$(echo "$subsection_name" | sed 's/_/-/g')

            echo "\subsection{${clean_subsection_name}}" >> "$tex_filename"
            echo " " >> "$tex_filename"
            echo " " >> "$tex_filename"
            echo "\begin{verbatim}" >> "$tex_filename"

            dos2unix "$name"   # Convert the line endings of the file to append
            cat "$name" >> "$tex_filename"

            echo "\end{verbatim}" >> "$tex_filename"
            echo " " >> "$tex_filename"
            echo " " >> "$tex_filename"

            echo " "
            echo "Subsection ${clean_subsection_name} created."
            echo " "

        fi
    done < sections.csv


    echo "\end{document}" >> "$tex_filename"

    for i in {1..3}; do
        pdflatex $tex_filename
    done
    
        
    mv *.pdf .. ; mv *.csv .. ; mv *.tex  ; rm *.aux ; rm *.toc ; rm *.log
}

# Current directory
cur_dir=$(pwd)

# Script location 
script=${BASH_SOURCE[0]}
script_dir=$(dirname "$script")


option=${ARGS[0]}

case $option in
    -help|--help)
        echo "To extract verbatim content,"
        echo "Provide a .tex file as first argument."
        echo "Plus, a file extention as second argument." ; exit;;
    *)
        files_in_current_dir=$(ls "${script_dir}")

        if cd "$script_dir/$option" >/dev/null 2>&1; then

            # Call the function with the desired starting directory
            recursively_search_files "${cur_dir}/${option}" cc

            create_tex_file "$option"

        else
            echo "Chosen dir not found"
            echo "Exiting."
            exit
        fi;;

esac
