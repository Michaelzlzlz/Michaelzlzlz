function myFunction() {
    var input, filter, ul, li, a, i;
    input = document.getElementById('input1');
    filter = input.value.toUpperCase();
    ul = document.getElementById("kollect2");
    li = ul.getElementsByTagName('li');

    for (i = 0; i < li.length; i++) {
        a = li[i].getAttribute("name");
        /*console.log(a);
        console.log(filter);*/
        if (a.toUpperCase().indexOf(filter) > -1) {
            li[i].style.display = '';
        } else {
            li[i].style.display = 'none';

        }
    }
}