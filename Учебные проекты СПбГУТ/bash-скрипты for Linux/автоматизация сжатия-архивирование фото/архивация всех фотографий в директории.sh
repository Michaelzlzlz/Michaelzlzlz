#!/usr/bin/
cd /var/www/html/paint/50_PhotoIn
for i in *.jpg;
do
convert $i -resize 70% /var/www/html/paint/50_PhotoSyte/$i;
zip -9 /var/www/html/paint/50_PhotoArh/$i.zip $i;
done
