let body = document.querySelector('.body');
let tdeme = document.querySelector('.tdeme-btn');
let lang = document.querySelector('.lang-btn');
let randColor = document.querySelector('.rand-color');
let logo = document.querySelector('.logo');
let userName = document.querySelector('.user-Name');
let pass = document.querySelector('.pass');
let validation = document.querySelector('.validation');
let forget = document.querySelector('.forget');
let links = document.querySelectorAll('.nav-link');
let label = document.querySelectorAll('.label');
let login = document.querySelector('.login-btn');

let isDark = false;
let isArabic = false;

tdeme.addEventListener('click', () => {
    isDark = !isDark;
    body.classList.toggle('dark');
    if (isArabic) {
        tdeme.textContent = isDark ? 'الوضع الفاتح' : 'الوضع الليلي '
    } else {

        tdeme.textContent = isDark ? 'ligth' : 'dark'
    }
})
lang.addEventListener('click', () => {
    isArabic = !isArabic;
    isArabic ? Arabic() : English();
    if (isArabic) {
        tdeme.textContent = isDark ? 'الوضع الفاتح' : 'الوضع الليلي '
    } else {

        tdeme.textContent = isDark ? 'ligth' : 'dark'
    }
})


function Arabic() {
    logo.innerthML = 'لوفي <span class="logo-span">الورفلي</span> '
    links[0].textContent = 'الرائيسية '
    links[1].textContent = 'المهارات'
    links[2].textContent = 'تواصل معي '
    links[3].textContent = 'الخدمات'
    links[4].textContent = 'عني'
    lang.textContent = 'English'
    label[0].textContent = 'اكتب رقم الهاتف او البريد الالكتروني'
    label[1].textContent = 'ادخل كلمة المرور'
    login.textContent = 'تسجيل الدخول'
    forget.textContent = 'نسيت كلمة المرور؟'
    validation.textContent = 'كلمة المرور او اسم المستخدم غير صحيحة'
    document.dir = 'rtl'
}
function English() {

    logo.innerthML = 'loufe<span class="logo-span">alwerfali</span>'
    links[0].textContent = 'home '
    links[1].textContent = 'skills'
    links[2].textContent = ' contact me '
    links[3].textContent = 'services'
    links[4].textContent = 'about me'
    lang.textContent = 'اللغة العربية '
    label[0].textContent = 'phone or email'
    label[1].textContent = 'password'
    login.textContent = 'login'
    forget.textContent = 'forget password?'
    validation.textContent = 'password no validation'
    document.dir = 'ltr'
}

login.addEventListener('click',()=>{
    let user = userName.value.trim();
    let password = pass.value.trim();
    if (user == 'admin' && password == '12345678') {
        location.href = '../website/public/calculate.thml'
        validation.style.opacity ='0';
        pass.style.border = '1px solid green'
        userName.style.border = '1px solid green'
    }else{
        validation.style.opacity ='1';
        pass.style.border = '1px solid red'
        userName.style.border = '1px solid red'
    }
})
randColor.addEventListener('click',()=>{
    location.href = 'refers.thml'
})