function myFunction() {
    var input, filter, ul, li, a, i;
    input = document.getElementById('input1');
    filter = input.value.toUpperCase();
    div = document.getElementById("katalog");
    div = div.getElementsByTagName('div');

    for (i = 0; i < div.length; i++) {
        a = div[i].getAttribute("name");
        /*console.log(a);
        console.log(filter);*/
        if (a.toUpperCase().indexOf(filter) > -1) {
            div[i].style.display = '';
        } else {
            div[i].style.display = 'none';

        }
    }
}