let input = document.querySelectorAll(".inp")
let btn = document.querySelector(".login")
let error = document.querySelector(".error")
let print = document.querySelector(".print")

btn.addEventListener('click',(e)=>{
    e.preventDefault();
    let valUser = input[0].value.trim();
    let valPass = input[1].value.trim();
    validation(valUser , valPass)
})

function validation(User , pass){
    if (User == 'admin' && pass == '12345') {
        location.href = './calculate.html'
    }else{
        error.textContent = 'error'
    }
}
print.addEventListener('click',()=>{
    window.open("https://google.com")
})