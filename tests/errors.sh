cp ../LS/uls .

zsh compare.sh <(ls --l 2>&1) <(./uls --l 2>&1) "--l"
zsh compare.sh <(ls --l . 2>&1) <(./uls --l . 2>&1) "--l ."
zsh compare.sh <(ls --l .. 2>&1) <(./uls --l .. 2>&1) "--l .."

zsh compare.sh <(ls privet 2>&1) <(./uls privet 2>&1) "privet"
zsh compare.sh <(ls privet . 2>&1) <(./uls privet . 2>&1) "privet ."
zsh compare.sh <(ls privet .. 2>&1) <(./uls privet .. 2>&1) "privet .."

zsh compare.sh <(ls --privet 2>&1) <(./uls --privet 2>&1) "--privet"
zsh compare.sh <(ls --privet . 2>&1) <(./uls --privet . 2>&1) "--privet ."
zsh compare.sh <(ls --privet .. 2>&1) <(./uls --privet .. 2>&1) "--privet .."

zsh compare.sh <(ls -- privet 2>&1) <(./uls -- privet 2>&1) "-- privet"
zsh compare.sh <(ls -- privet . 2>&1) <(./uls -- privet . 2>&1) "-- privet ."
zsh compare.sh <(ls -- privet .. 2>&1) <(./uls -- privet .. 2>&1) "-- privet .."

zsh compare.sh <(ls -- -privet 2>&1) <(./uls -- -privet 2>&1) "-- -privet"
zsh compare.sh <(ls -- -privet . 2>&1) <(./uls -- -privet . 2>&1) "-- -privet ."
zsh compare.sh <(ls -- -privet .. 2>&1) <(./uls -- -privet .. 2>&1) "-- -privet .."

zsh compare.sh <(ls /Users/oafanasiev/Desktop/privet 2>&1) <(./uls /Users/oafanasiev/Desktop/privet 2>&1) "/Users/oafanasiev/Desktop/privet"
zsh compare.sh <(ls /Users/oafanasiev/Desktop/privet . 2>&1) <(./uls /Users/oafanasiev/Desktop/privet . 2>&1) "/Users/oafanasiev/Desktop/privet ."
zsh compare.sh <(ls /Users/oafanasiev/Desktop/privet .. 2>&1) <(./uls /Users/oafanasiev/Desktop/privet .. 2>&1) "/Users/oafanasiev/Desktop/privet .."

zsh compare.sh <(ls /Users/abalabin/Desktop/privet 2>&1) <(./uls /Users/abalabin/Desktop/privet 2>&1) "/Users/abalabin/Desktop/privet"
zsh compare.sh <(ls /Users/abalabin/Desktop/privet . 2>&1) <(./uls /Users/abalabin/Desktop/privet . 2>&1) "/Users/abalabin/Desktop/privet ."
zsh compare.sh <(ls /Users/abalabin/Desktop/privet .. 2>&1) <(./uls /Users/abalabin/Desktop/privet .. 2>&1) "/Users/abalabin/Desktop/privet .."

zsh compare.sh <(ls /Users/neo 2>&1) <(./uls /Users/neo 2>&1) "/Users/neo"
zsh compare.sh <(ls /Users/neo . 2>&1) <(./uls /Users/neo . 2>&1) "/Users/neo ."
zsh compare.sh <(ls /Users/neo .. 2>&1) <(./uls /Users/neo .. 2>&1) "/Users/neo .."

zsh compare.sh <(ls /Users/neo/ 2>&1) <(./uls /Users/neo/ 2>&1) "/Users/neo/"
zsh compare.sh <(ls /Users/neo/ . 2>&1) <(./uls /Users/neo/ . 2>&1) "/Users/neo/ ."
zsh compare.sh <(ls /Users/neo/ .. 2>&1) <(./uls /Users/neo/ .. 2>&1) "/Users/neo/ .."

zsh compare.sh <(ls /Users/neo/Desktop 2>&1) <(./uls /Users/neo/Desktop 2>&1) "/Users/neo/Desktop"
zsh compare.sh <(ls /Users/neo/Desktop . 2>&1) <(./uls /Users/neo/Desktop . 2>&1) "/Users/neo/Desktop ."
zsh compare.sh <(ls /Users/neo/Desktop .. 2>&1) <(./uls /Users/neo/Desktop .. 2>&1) "/Users/neo/Desktop .."

zsh compare.sh <(ls /Users/neo/Desktop/ 2>&1) <(./uls /Users/neo/Desktop/ 2>&1) "/Users/neo/Desktop/"
zsh compare.sh <(ls /Users/neo/Desktop/ . 2>&1) <(./uls /Users/neo/Desktop/ . 2>&1) "/Users/neo/Desktop/ ."
zsh compare.sh <(ls /Users/neo/Desktop/ .. 2>&1) <(./uls /Users/neo/Desktop/ .. 2>&1) "/Users/neo/Desktop/ .."

zsh compare.sh <(ls empty_folder 2>&1) <(./uls empty_folder 2>&1) "empty_folder"
zsh compare.sh <(ls empty_folder . 2>&1) <(./uls empty_folder . 2>&1) "empty_folder ."
zsh compare.sh <(ls empty_folder .. 2>&1) <(./uls empty_folder .. 2>&1) "empty_folder .."

zsh compare.sh <(ls empty_folder/ 2>&1) <(./uls empty_folder/ 2>&1) "empty_folder/"
zsh compare.sh <(ls empty_folder/ . 2>&1) <(./uls empty_folder/ . 2>&1) "empty_folder/ ."
zsh compare.sh <(ls empty_folder/ .. 2>&1) <(./uls empty_folder/ .. 2>&1) "empty_folder/ .."

zsh compare.sh <(ls empty_folder/file 2>&1) <(./uls empty_folder/file 2>&1) "empty_folder/file"
zsh compare.sh <(ls empty_folder/file . 2>&1) <(./uls empty_folder/file . 2>&1) "empty_folder/file ."
zsh compare.sh <(ls empty_folder/file .. 2>&1) <(./uls empty_folder/file .. 2>&1) "empty_folder/file .."

zsh compare.sh <(ls empty_folder/file/ 2>&1) <(./uls empty_folder/file/ 2>&1) "empty_folder/file/"
zsh compare.sh <(ls empty_folder/file/ . 2>&1) <(./uls empty_folder/file/ . 2>&1) "empty_folder/file/ ."
zsh compare.sh <(ls empty_folder/file/ .. 2>&1) <(./uls empty_folder/file/ .. 2>&1) "empty_folder/file/ .."

zsh compare.sh <(ls ./empty_folder 2>&1) <(./uls ./empty_folder 2>&1) "./empty_folder"
zsh compare.sh <(ls ./empty_folder . 2>&1) <(./uls ./empty_folder . 2>&1) "./empty_folder ."
zsh compare.sh <(ls ./empty_folder .. 2>&1) <(./uls ./empty_folder .. 2>&1) "./empty_folder .."

zsh compare.sh <(ls ./empty_folder/ 2>&1) <(./uls ./empty_folder/ 2>&1) "./empty_folder/"
zsh compare.sh <(ls ./empty_folder/ . 2>&1) <(./uls ./empty_folder/ . 2>&1) "./empty_folder/ ."
zsh compare.sh <(ls ./empty_folder/ .. 2>&1) <(./uls ./empty_folder/ .. 2>&1) "./empty_folder/ .."

zsh compare.sh <(ls ./empty_folder/file 2>&1) <(./uls ./empty_folder/file 2>&1) "./empty_folder/file"
zsh compare.sh <(ls ./empty_folder/file . 2>&1) <(./uls ./empty_folder/file . 2>&1) "./empty_folder/file ."
zsh compare.sh <(ls ./empty_folder/file .. 2>&1) <(./uls ./empty_folder/file .. 2>&1) "./empty_folder/file .."

zsh compare.sh <(ls ./empty_folder/file/ 2>&1) <(./uls ./empty_folder/file/ 2>&1) "./empty_folder/file/"
zsh compare.sh <(ls ./empty_folder/file/ . 2>&1) <(./uls ./empty_folder/file/ . 2>&1) "./empty_folder/file/ ."
zsh compare.sh <(ls ./empty_folder/file/ .. 2>&1) <(./uls ./empty_folder/file/ .. 2>&1) "./empty_folder/file/ .."

zsh compare.sh <(ls '- -' 2>&1) <(./uls '- -' 2>&1) "'- -''"
zsh compare.sh <(ls '- -' . 2>&1) <(./uls '- -' . 2>&1) "'- -' ."
zsh compare.sh <(ls '- -' .. 2>&1) <(./uls '- -' .. 2>&1) "'- -' .."

zsh compare.sh <(ls ' --' 2>&1) <(./uls ' --' 2>&1) "' --'"
zsh compare.sh <(ls ' --' . 2>&1) <(./uls ' --' . 2>&1) "' --' ."
zsh compare.sh <(ls ' --' .. 2>&1) <(./uls ' --' .. 2>&1) "' --' .."

zsh compare.sh <(ls '-- ' 2>&1) <(./uls '-- ' 2>&1) "'-- '"
zsh compare.sh <(ls '-- ' . 2>&1) <(./uls '-- ' . 2>&1) "'-- ' ."
zsh compare.sh <(ls '-- ' .. 2>&1) <(./uls '-- ' .. 2>&1) "'-- ' .."

zsh compare.sh <(ls -l -- -C 2>&1) <(./uls -l -- -C 2>&1) "-l -- -C"
zsh compare.sh <(ls -l -- -C . 2>&1) <(./uls -l -- -C . 2>&1) "-l -- -C ."
zsh compare.sh <(ls -l -- -C .. 2>&1) <(./uls -l -- -C .. 2>&1) "-l -- -C .."
