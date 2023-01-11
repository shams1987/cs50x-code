// using regex
function ValidateEmail(inputText) {
    // defining the format using regex formula
    var mailformat = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
    //  input is a match
    if (inputText.value.match(mailformat)) {
        alert("Valid email address!");
        document.form1.text1.focus();
        return true;
    }
    // not a match
    else {
        alert("You have entered an invalid email address!");
        document.form1.text1.focus();
        return false;
    }
}