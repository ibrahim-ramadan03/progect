let arabic = document.querySelectorAll(".num");
let screen = document.querySelector(".screen");
arabic.forEach(arabic => {
    arabic.addEventListener('click',()=>{
        let value = arabic.textContent;
        cal(value)
    })
});

function cal(value){
    switch (true) {
        case value == 'ac':
            screen.textContent = ''
            return;
    
        case value == 'c':
            screen.textContent = screen.textContent.slice(0,-1);
            return;
    
        case value == '=':
            screen.textContent = eval(screen.textContent)
            return;
    
        case value == '=':
            screen.textContent = eval(screen.textContent)
            return;
    
        default:
            break;
    }
    screen.textContent += value;
}