$(document).ready(function() {/*проверка совпадения паролей*/
       		 	$('#подтвердить').change(function() {
            		var pass1 = $("#пороль").val();
            		var pass2 = $("#подтвердить").val();
            		if (pass1 != pass2) {
            		    $("#подтвердить").css('border', 'red 1px solid');
                		$('#inform1').html('<em>Пароли не совпадают!!!</em>');
            		}
            		else { 
            			$("#подтвердить").css('border', 'black 2px solid');
                		$('#inform1').html('Пароли совпадают');}
        		});
    		});

function check1() {/*проверка формы и обновление страницы*/
 	var pol = document.querySelector('#пол').checked;
	var sogl = document.querySelector('#согласие').checked;
	if ((имя.validity.valueMissing == false) && (фам.validity.valueMissing == false) &&
		(age.validity.valueMissing == false) && (email.validity.valueMissing == false)&&
		(тел.validity.valueMissing == false)&&(пороль.validity.valueMissing == false)&&
		(подтвердить.validity.valueMissing == false) &&(имя.validity.patternMismatch == false) && 
		(фам.validity.patternMismatch == false) && (email.validity.patternMismatch == false)&&
		(тел.validity.patternMismatch == false)&&(пороль.validity.patternMismatch == false)&&
		(подтвердить.validity.patternMismatch == false)&&(pol)&&(sogl)) 
		{document.write('<body bgcolor="#666666"><h3 align="center" style="color: #FFFFFF">Поздравляем! Вы зарегистрированы!!!</h3><a align="center" href="home.html"><h3>Назад</h3></a></body>');} else {$('#inform1').html('<em>Все поля должны быть заполнены и отмечены!</em>');}
}


function check2() {/*проверка формы и обновление страницы*/
	if ((email.validity.patternMismatch == false)&&
		(пороль.validity.patternMismatch == false)) 
		{document.write('<body bgcolor="#666666"><h3 align="center" style="color: #FFFFFF">Поздравляем! Вы вошли!</h3><a align="center" href="home.html"><h3>Назад</h3></a></body>');} else {$('#inform1').html('<em>Все поля должны быть заполнены и отмечены!</em>');}
}