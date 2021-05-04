function changeDisplayLanguage(cls, id) {
    var lists = document.getElementsByClassName(cls);
    for (var i = 0; i < lists.length; i++) {
        lists[i].style.display = 'none';
    }
    document.getElementById(id).style.display = "block";
}

function changeDisplayCode(cls, id) {
    document.getElementById("code_title").innerHTML = id;
    var lists = document.getElementsByClassName(cls);
    for (var i = 0; i < lists.length; i++) {
        lists[i].style.display = 'none';
    }
    document.getElementById(id).style.display = "block";
}
