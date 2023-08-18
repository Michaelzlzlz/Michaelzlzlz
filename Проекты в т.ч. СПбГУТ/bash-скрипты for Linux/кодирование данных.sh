md IST932_Zurikov_Michael 
cd IST932_Zurikov_Michael
chcp 866
echo Зюриков Михаил Артурович 29.06.2001 Санкт-Петербург > 1.txt
chcp 1251
echo Зюриков Михаил Артурович 29.06.2001 Санкт-Петербург > 2.txt
chcp 65001
echo Зюриков Михаил Артурович 29.06.2001 Санкт-Петербург > 3.txt
type 1.txt > result.txt
type 2.txt >> result.txt
type 3.txt >> result.txt
cd ..
type IST932_Zurikov_Michael\result.txt
