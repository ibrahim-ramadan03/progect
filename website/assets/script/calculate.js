let arabic = document.querySelectorAll('.num');
let screen = document.querySelector('.screen');

let operator = ["/", "*", "-", "+", "%"];

arabic.forEach(arabic => {
    arabic.addEventListener('click', () => {
        let value = arabic.textContent;
        cal(value);
    });
});

function cal(value) {
    let lastNumber = screen.textContent.slice(0, -1);
    let last = screen.textContent.slice(-1);

    switch (true) {

        case value == 'ac':
            screen.textContent = '';
            return;

        case value == 'c':
            screen.textContent = lastNumber;
            return;

        
        case operator.includes(value) && screen.textContent == '':
            return;

        case operator.includes(value) && operator.includes(last):
            screen.textContent = lastNumber + value;
            return;

        case value == '.' && screen.textContent == '':
            screen.textContent = '0.';
            return;

        case value == '.' && last == '.':
            return;

        case value == '.':
            let cutArray = screen.textContent.split(/[+\-*/%]/);
            let newArray = cutArray.at(-1);

            if (newArray.includes('.')) {
                return;
            } else {
                screen.textContent += value;
            }
            return;

        case value == '=':
            try {
                let cutArray = screen.textContent;

                screen.textContent = eval(cutArray);
            } catch {
                screen.textContent = 'عملية خاطئة';
            }
            return;

        default:
            break;
    }

    screen.textContent += value;
}