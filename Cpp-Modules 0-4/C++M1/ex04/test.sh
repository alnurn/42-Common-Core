#!/bin/bash

./sed "tests/inputs/01_english_basic.txt" "Hello" "Hi"
diff "tests/inputs/01_english_basic.txt.replace"  "tests/expected/01_english_basic.txt.replace" 
if [ $? -eq 0 ]; then
	echo "1) OK"
else
	echo "1) FAIL"
fi

./sed "tests/inputs/02_english_repeated.txt" "ana" "X"
diff "tests/inputs/02_english_repeated.txt.replace"  "tests/expected/02_english_repeated.txt.replace" 
if [ $? -eq 0 ]; then
	echo "2) OK"
else
	echo "2) FAIL"
fi

./sed "tests/inputs/03_expand.txt" "a" "aaaa"
diff "tests/inputs/03_expand.txt.replace"  "tests/expected/03_expand.txt.replace" 
if [ $? -eq 0 ]; then
	echo "3) OK"
else
	echo "3) FAIL"
fi

./sed "tests/inputs/04_delete.txt" "red" ""
diff "tests/inputs/04_delete.txt.replace"  "tests/expected/04_delete.txt.replace" 
if [ $? -eq 0 ]; then
	echo "4) OK"
else
	echo "4) FAIL"
fi

./sed "tests/inputs/05_no_match.txt" "elephant" "mouse"
diff "tests/inputs/05_no_match.txt.replace"  "tests/expected/05_no_match.txt.replace" 
if [ $? -eq 0 ]; then
	echo "5) OK"
else
	echo "5) FAIL"
fi

./sed "tests/inputs/06_digits.txt" "123" "9"
diff "tests/inputs/06_digits.txt.replace"  "tests/expected/06_digits.txt.replace" 
if [ $? -eq 0 ]; then
	echo "6) OK"
else
	echo "6) FAIL"
fi

./sed "tests/inputs/07_symbols.txt" "a+b?" "Z"
diff "tests/inputs/07_symbols.txt.replace"  "tests/expected/07_symbols.txt.replace" 
if [ $? -eq 0 ]; then
	echo "7) OK"
else
	echo "7) FAIL"
fi

./sed "tests/inputs/08_overlap.txt" "aa" "X"
diff "tests/inputs/08_overlap.txt.replace"  "tests/expected/08_overlap.txt.replace" 
if [ $? -eq 0 ]; then
	echo "8) OK"
else
	echo "8) FAIL"
fi

./sed "tests/inputs/09_newline_match.txt" "one
two" "ONE-TWO"
diff "tests/inputs/09_newline_match.txt.replace"  "tests/expected/09_newline_match.txt.replace" 
if [ $? -eq 0 ]; then
	echo "9) OK"
else
	echo "9) FAIL"
fi

./sed "tests/inputs/10_empty_file.txt" "hello" "bye"
diff "tests/inputs/10_empty_file.txt.replace"  "tests/expected/10_empty_file.txt.replace" 
if [ $? -eq 0 ]; then
	echo "10) OK"
else
	echo "10) FAIL"
fi

./sed "tests/inputs/11_no_final_newline.txt" "line" "ROW"
diff "tests/inputs/11_no_final_newline.txt.replace"  "tests/expected/11_no_final_newline.txt.replace" 
if [ $? -eq 0 ]; then
	echo "11) OK"
else
	echo "11) FAIL"
fi

./sed "tests/inputs/12_russian.txt" "Привет" "Здравствуйте"
diff "tests/inputs/12_russian.txt.replace"  "tests/expected/12_russian.txt.replace" 
if [ $? -eq 0 ]; then
	echo "12) OK"
else
	echo "12) FAIL"
fi

./sed "tests/inputs/13_russian_delete.txt" "кошка" ""
diff "tests/inputs/13_russian_delete.txt.replace"  "tests/expected/13_russian_delete.txt.replace" 
if [ $? -eq 0 ]; then
	echo "13) OK"
else
	echo "13) FAIL"
fi

./sed "tests/inputs/14_chinese.txt" "你好" "您好"
diff "tests/inputs/14_chinese.txt.replace"  "tests/expected/14_chinese.txt.replace" 
if [ $? -eq 0 ]; then
	echo "14) OK"
else
	echo "14) FAIL"
fi

./sed "tests/inputs/15_chinese_char.txt" "猫" "老虎"
diff "tests/inputs/15_chinese_char.txt.replace"  "tests/expected/15_chinese_char.txt.replace" 
if [ $? -eq 0 ]; then
	echo "15) OK"
else
	echo "15) FAIL"
fi

./sed "tests/inputs/16_mixed.txt" "123" "NUM"
diff "tests/inputs/16_mixed.txt.replace"  "tests/expected/16_mixed.txt.replace" 
if [ $? -eq 0 ]; then
	echo "16) OK"
else
	echo "16) FAIL"
fi

./sed "tests/inputs/17_mixed_utf8.txt" "кот" "тигр"
diff "tests/inputs/17_mixed_utf8.txt.replace" "tests/expected/17_mixed_utf8.txt.replace"
if [ $? -eq 0 ]; then
	echo "17) OK"
else
	echo "17) FAIL"
fi

./sed "tests/inputs/18_same.txt" "repeat" "repeat"
diff "tests/inputs/18_same.txt.replace" "tests/expected/18_same.txt.replace"
if [ $? -eq 0 ]; then
	echo "18) OK"
else
	echo "18) FAIL"
fi

./sed "tests/inputs/19_case_sensitive.txt" "test" "done"
diff "tests/inputs/19_case_sensitive.txt.replace" "tests/expected/19_case_sensitive.txt.replace"
if [ $? -eq 0 ]; then
	echo "19) OK"
else
	echo "19) FAIL"
fi

./sed "tests/inputs/20_whitespace.txt" " " "_"
diff "tests/inputs/20_whitespace.txt.replace" "tests/expected/20_whitespace.txt.replace"
if [ $? -eq 0 ]; then
	echo "20) OK"
else
	echo "20) FAIL"
fi

./sed "tests/inputs/21_empty_replace_at_end.txt" "abc" ""
diff "tests/inputs/21_empty_replace_at_end.txt.replace" "tests/expected/21_empty_replace_at_end.txt.replace"
if [ $? -eq 0 ]; then
	echo "21) OK"
else
	echo "21) FAIL"
fi

./sed "tests/inputs/22 file name with spaces.txt" "spaces" "gaps"
diff "tests/inputs/22 file name with spaces.txt.replace" "tests/expected/22 file name with spaces.txt.replace"
if [ $? -eq 0 ]; then
	echo "22) OK"
else
	echo "22) FAIL"
fi

./sed "tests/inputs/23_utf8_replace_ascii.txt" "é" "e"
diff "tests/inputs/23_utf8_replace_ascii.txt.replace" "tests/expected/23_utf8_replace_ascii.txt.replace"
if [ $? -eq 0 ]; then
	echo "23) OK"
else
	echo "23) FAIL"
fi

./sed "tests/inputs/24_utf8_emoji.txt" "😀" "🦊"
diff "tests/inputs/24_utf8_emoji.txt.replace" "tests/expected/24_utf8_emoji.txt.replace"
if [ $? -eq 0 ]; then
	echo "24) OK"
else
	echo "24) FAIL"
fi

rm tests/inputs/*.replace
