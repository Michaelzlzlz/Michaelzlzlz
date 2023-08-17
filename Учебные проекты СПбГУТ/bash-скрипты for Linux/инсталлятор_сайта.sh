#!/usr/bin/sh
#информации и ошибки не будут отображаться (весь этот хлам будто улетят в черную дыру)
apt update > /dev/null 2>&1 
apt install dialog > /dev/null 2>&1 
DIALOG=${DIALOG=dialog} 
insta=0 #установлено или нет
Iname=`mktemp 2>/dev/null` || Iname=/tmp/test$$
trap "rm -f $Iname" 0 1 2 5 15
$DIALOG --title "Инсталлятор сайта" --clear \
--inputbox "Вас приветствует инсталлятор сайта, введите ваше имя:" 10 40 2>$Iname
case $? in
 0)
 $DIALOG --title "Инсталлятор сайта" --clear \
          --yesno "`cat $Iname`, здравствуйте, вы хотите что-нибудь установить?" 10 40
  case $? in
      0)
    $DIALOG --title "Инсталлятор сайта" --clear \
          --yesno "`cat $Iname`, вы уверены?\n\nПроверьте, есть ли на вашем диске 650 Мб?" 10 40 
    case $? in
        0)
      itog=0
      while [ $itog = 0 ]
       do
        Tname=`mktemp 2>/dev/null` || Tname=/tmp/test$$
        trap "rm -f $Tname" 0 1 2 5 15     
        $DIALOG --clear --title "Инсталлятор сайта" --menu "`cat $Iname`, выберите что вы желаете установить?" 20 61 4\
         "1" "Сайт студента Зюриков Михаил ИСТ-932"\
         "2" "Amigo Browser" \
         "3" "Yandex Быстрый Browser" \
         "4" "Yandex Super-Быстрый Browser" \
         "5" "Yandex Ultra-Быстрый Browser" \
         "6" "Yandex Ultra-super-duper-Быстрый Browser с VPN" \
         "7" "Видеокарта GeForce RTX 3080 Ti GamingPro" \
         "8" "Оперативная память GDDR6 32ГБ" 2>$Tname
         retval=$?
        info=`cat $Tname`
        case $retval in
         1)
          itog=2
         ;;
         255)
          itog=3
         ;;
         0)
          case $info in
           1)
            itog=1
            i_j=1
            {     
             while test $i_j != 20
             do
              echo $i_j
              echo "XXX"
              echo "Идет установка: $i_j процентов"
              echo "(?) Установка apache2"
              echo "XXX"
              i_j=`expr $i_j + 1`
              sleep 0.2
             done
            } | $DIALOG --title "Инсталлятор сайта" --gauge "Подождите, сейчас идет установка" 20 70 0
            apt-get install apache2 > /dev/null 2>&1
            clear   
            i_j=20
            {
             while test $i_j != 30
             do
              echo $i_j
              echo "XXX"
              echo "Идет установка: $i_j процентов"
              echo "(+) Установлена apache2"
              echo "(?) Идет запуск и настройка apache2"
              echo "XXX"
              i_j=`expr $i_j + 1`
              sleep 0.4
             done
            } | $DIALOG --title "Инсталлятор сайта" --gauge "Подождите, сейчас идет установка" 20 70 0
            systemctl start apache2 > /dev/null 2>&1 
            clear
            i_j=30
            {
             while test $i_j != 45
             do
              echo $i_j
              echo "XXX"
              echo "Идет установка: $i_j процентов"
              echo "(+) Установлена apache2"
              echo "(+) Успешно запущена и настроена apache2"
              echo "(?) Установка unzip"
              echo "XXX"
              i_j=`expr $i_j + 1`
              sleep 0.2
             done
            } | $DIALOG --title "Инсталлятор сайта" --gauge "Подождите, сейчас идет установка" 20 70 0

            apt-get install unzip > /dev/null 2>&1 
            clear 

            i_j=45
            {
             while test $i_j != 65
             do
              echo $i_j
              echo "XXX"
              echo "Идет установка: $i_j процентов"
              echo "(+) Установлена apache2"
              echo "(+) Успешно запущена и настроена apache2"
              echo "(+) Установлена unzip"
              echo "(?) Удаление устаревших файлов и директорий"
              echo "XXX"
              i_j=`expr $i_j + 1`
              sleep 0.1
             done
            } | $DIALOG --title "Инсталлятор сайта" --gauge "Подождите, сейчас идет установка" 20 70 0
            rm -R /var/www/html > /dev/null 2>&1
            clear
            i_j=65
            {
             while test $i_j != 85
             do
              echo $i_j
              echo "XXX"
              echo "Идет установка: $i_j процентов"
              echo "(+) Установлена apache2"
              echo "(+) Успешно запущена и настроена apache2"
              echo "(+) Установлена unzip"
              echo "(+) Удалены устаревшие файлы и директории"
              echo "(?) Идёт распаковка архива\n\n(Подождите 1-2 минуты)"
              echo "XXX"
              i_j=`expr $i_j + 1`
              sleep 0.05
             done
            } | $DIALOG --title "Инсталлятор сайта" --gauge "Подождите, сейчас идет установка" 20 70 0
            unzip html.zip > /dev/null 2>&1
            clear
            i_j=85
            {
             while test $i_j != 95
             do
              echo $i_j
              echo "XXX"
              echo "Идет установка: $i_j процентов"
              echo "(+) Установлена apache2"
              echo "(+) Успешно запущена и настроена apache2"
              echo "(+) Установлена unzip"
              echo "(+) Удалены устаревшие файлы и директории"
              echo "(+) Успешно распакованы файлы"
              echo "(?) Загрузка файлов в /var/www/"
              echo "XXX"
              i_j=`expr $i_j + 1`
              sleep 0.3
             done
            } | $DIALOG --title "Инсталлятор сайта" --gauge "Подождите, сейчас идет установка" 20 70 0
            mv html /var/www/ > /dev/null 2>&1 
            clear 

            i_j=95
            {
             while test $i_j != 98
             do
              echo $i_j
              echo "XXX"
              echo "Идет установка: $i_j процентов"
              echo "(+) Установлена apache2"
              echo "(+) Успешно запущена и настроена apache2"
              echo "(+) Установлена unzip"
              echo "(+) Удалены устаревшие файлы и директории"
              echo "(+) Успешно распакованы файлы"
              echo "(+) Успешно загружены файлы в /var/www/"
              echo "(?) Удаление временных файлов"
              echo "XXX"
              i_j=`expr $i_j + 1`
              sleep 0.3
             done
            } | $DIALOG --title "Инсталлятор сайта" --gauge "Подождите, сейчас идет установка" 20 70 0
            rm -R html > /dev/null 2>&1
            clear
            i_j=95
            {
             while test $i_j != 98
             do
              echo $i_j
              echo "XXX"
              echo "Идет установка: $i_j процентов"
              echo "(+) Установлена apache2"
              echo "(+) Успешно запущена и настроена apache2"
              echo "(+) Установлена unzip"
              echo "(+) Удалены устаревшие файлы и директории"
              echo "(+) Успешно распакованы файлы"
              echo "(+) Успешно загружены файлы в /var/www/"
              echo "(+) Удалены временные файлы"
              echo "XXX"
              i_j=`expr $i_j + 1`
              sleep 0.3
             done
            } | $DIALOG --title "Инсталлятор сайта" --gauge "Подождите, сейчас идет установка" 20 70 0
            clear
            echo "Установка прошла успешно!"
            insta=1
           ;;
           2)
            $DIALOG --title "Инсталлятор сайта" --msgbox "Amigo Browser мы устанавливать не будем: в инсталляторе есть только сайт." 10 60
           ;;  
           3)
            $DIALOG --title "Инсталлятор сайта" --msgbox "Yandex Быстрый Browser мы устанавливать не будем: в инсталляторе есть только сайт." 10 60
           ;;  
           4)
            $DIALOG --title "Инсталлятор сайта" --msgbox "Yandex Super-Быстрый Browser мы устанавливать не будем: в инсталляторе есть только сайт." 10 60
           ;;  
           5)
            $DIALOG --title "Инсталлятор сайта" --msgbox "Yandex Ultra-Быстрый Browser мы устанавливать не будем: в инсталляторе есть только сайт." 10 60
           ;;
           6)
            $DIALOG --title "Инсталлятор сайта" --msgbox "Yandex Ultra-super-duper-Быстрый Browser с VPN мы устанавливать не будем: в инсталляторе есть только сайт." 10 60
           ;;  
           7)
            $DIALOG --title "Инсталлятор сайта" --msgbox "Видеокарту GeForce RTX 3080 Ti GamingPro мы устанавливать не будем: в инсталляторе есть только сайт." 10 60
           ;;  
           8)
            $DIALOG --title "Инсталлятор сайта" --msgbox "Оперативную память GDDR6 32ГБ мы устанавливать не будем: в инсталляторе есть только сайт." 10 60
           ;;   
          esac
         ;;
        esac        
       done
       if [ $insta = 1 ]; then
       clear
       $DIALOG --title "Инсталлятор сайта" --msgbox "`cat $Iname`, установка сайта завершена!\n\n Желаю вам замечательного дня! :)" 10 40
       clear
       echo "Сайт успешно установлен по пути /var/www/"     
      fi 
      if [ $itog = 2 ]; then
       clear
       $DIALOG --title "Инсталлятор сайта" --msgbox "`cat $Iname`, до свидание! Приходите когда определитесь с выбором!" 10 40 
       clear
       echo "`cat $Iname`, до свидание! Приходите когда определитесь с выбором!"
      fi
      if [ $itog = 3 ]; then
       clear
       $DIALOG --title "Инсталлятор сайта" --msgbox "До свидание, `cat $Iname`! Вы нажали на ESC!" 10 30 
       clear
       echo "Вы нажали на ESC"
      fi 
     ;;
       1)
        $DIALOG --title "Инсталлятор сайта" --clear \
          --msgbox "До свидание, `cat $Iname`! Приходите когда будете готовы!" 10 40
           clear
     echo "До свидание, `cat $Iname`! Приходите когда будете готовы!"
     ;;
        255)
        $DIALOG --title "Инсталлятор сайта" --msgbox "До свидание, `cat $Iname`! Вы нажали на ESC!" 10 30 
     clear
     echo "Вы нажали на ESC";;
    esac
   ;;
      1)
   $DIALOG --title "Инсталлятор сайта" --clear \
          --msgbox "До свидание, `cat $Iname`! Приходите когда захотите установить что-нибудь." 10 40
     clear
   echo "До свидание, `cat $Iname`! Приходите когда захотите установить что-нибудь."
   ;;
      255)
      $DIALOG --title "Инсталлятор сайта" --msgbox "До свидание, `cat $Iname`! Вы нажали на ESC!" 10 30 
   clear
   echo "Вы нажали на ESC";;
  esac
 ;;
 1)
 $DIALOG --title "Инсталлятор сайта" --clear \
          --msgbox "До свидание, Гость!" 10 40
  clear
  echo "До свидание, Гость!" 
 ;;
 255)
  if test -s $Iname ; then
   cat $Iname
  else
   $DIALOG --title "Инсталлятор сайта" --msgbox "До свидание, Гость! Вы нажали на ESC!" 10 30 
   clear
   echo "Вы нажали на ESC"
  fi
 ;;
esac
