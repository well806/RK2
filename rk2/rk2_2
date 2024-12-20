#!/bin/bash
if [ $# -ne 2 ]; then
    echo "Пожалуйста, укажите директорию и расширение файлов."
    exit 1
fi
    
d=$1
e=$2

if [ ! -d "$d" ]; then
    echo "Директория не найдена."
    exit 1
fi

f=$(find "$d" -type f -name "*.$e")

if [ -z "$f" ]; then
    echo "Файлы с расширением $e не найдены."
else
    echo "Найденные файлы:"
    echo "$f"
fi
