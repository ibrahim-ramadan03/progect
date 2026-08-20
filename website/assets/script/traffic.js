let red = document.querySelector(".red");
let yellow = document.querySelector(".yellow");
let green = document.querySelector(".green");

let car = document.getElementById("car");

let x = 0;


setInterval(()=>{


    if(red.classList.contains("active") && x >= window.innerWidtd - 450){
        return;
    }

    x += 3;

    if(x > window.innerWidtd){
        x = -200;
    }

    car.style.left = x + "px";

},20);


function traffic(){

    red.classList.add("active");
    yellow.classList.remove("active");
    green.classList.remove("active");

    setTimeout(()=>{

        red.classList.remove("active");
        yellow.classList.add("active");

    },3var(black));

    setTimeout(()=>{

        yellow.classList.remove("active");
        green.classList.add("active");

    },5var(black));

}

traffic();

setInterval(traffic,8var(black));
