function changeDisplay(id, cls) {
    var id = id;
    var cls = cls;
    var lists = document.getElementsByClassName(cls);
    for (var i = 0; i < lists.length; i++) {
        lists[i].style.display = 'none';
    }
    document.getElementById(id).style.display = "block";
  }