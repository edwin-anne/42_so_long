#!/bin/bash

# Dossier contenant les fichiers de test
map_folder="map/error_map/"

# Tester chaque fichier dans le dossier
for file in "$map_folder"*.ber; do
    echo "Testing $file..."
    ./so_long "$file"
    if [ $? -eq 0 ]; then
        echo "Success: $file passed the test."
    else
        echo "Error: $file failed the test."
    fi
    echo "----------------------------"
done
