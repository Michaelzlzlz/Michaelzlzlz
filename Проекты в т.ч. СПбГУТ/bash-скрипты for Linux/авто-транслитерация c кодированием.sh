#!/usr/bin/sh

mkdir ИСТ-932_Зюриков
cd ИСТ-932_Зюриков
echo > 1.txt
for ((i=0; i < 100; i++)) do
     echo -e "Михаил Зюриков Артурович 29.06.2001 Санкт-Петербург \t Michael Zurikov Arturovich 29.06.2001 Sankt-Peterburg" >> 1.txt
done

for ((i=0; i < 25; i++)) do
    echo -e "Михаил Зюриков Артурович 29.06.2001 Санкт-Петербург \t Michael Zurikov Arturovich 29.06.2001 Sankt-Peterburg" | tr '[абвгдеёзжийклмнопрстуфхцчшщьыъэюяабвгдеёжзийклмнопрстуфхцчшщъыьэюяabcdefghijklmnopqrstuvwxyz]' '[АБВГДЕЁЗЖИЙКЛМНОПРСТУФХЦЧШЩЬЫЪЭЮЯАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯABCDEFGHIJKLMNOPQRSTUVWXYZ]' >> 1.txt
done 

# sed-ом заменяем символы кириллицы на символы латиницы
sed -i "y/авеснкморухтАВЕСНКМОРУХТ/abechkmopyxtABECHKMOPYXT/" 1.txt

iconv -f UTF-8 -t 866 -o 2.txt 1.txt 
iconv -f UTF-8 -t WINDOWS-1251 -o 3.txt 1.txt   
iconv -f UTF-8 -t ISO_8859-5 -o 4.txt 1.txt  
cat {1..4}.txt > result.txt  
#закодирован 2,3,4 и создан result.txt

for i in 1 2 3 4 result
do
    zip -9 $i.zip $i.txt
    bzip2 -k -9 $i.txt  
    gzip -k -9 $i.txt
    arj a $i.arj $i.txt
done
#все архивированы максимальным сжатием

tar -cvjf ИСТ-932_Зюриков_ЛР3-5.tar.bz2 *.zip *.gz *.bz2 *.arj
mv ИСТ-932_Зюриков_ЛР3-5.tar.bz2 ../ #тащим наверх
cd
rm -R ИСТ-932_Зюриков
clear
ls –ln
