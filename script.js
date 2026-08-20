const display = document.querySelector('#display');
const keys = document.querySelector('#keys');
let expression = '';

function render() {
  display.textContent = expression || '0';
}

function calculate() {
  if (!expression || /[+*/%-]$/.test(expression)) return;
  try {
    // Inputs are limited to calculator buttons before evaluation.
    const result = Function(`"use strict"; return (${expression})`)();
    expression = Number.isFinite(result) ? String(result) : 'خطأ';
  } catch {
    expression = 'خطأ';
  }
  render();
}

function input(value) {
  if (expression === 'خطأ') expression = '';
  const isOperator = '+-*/%'.includes(value);
  const last = expression.at(-1);

  if (isOperator && '+-*/%'.includes(last)) {
    expression = expression.slice(0, -1) + value;
  } else if (value === '.' && expression.split(/[+*/%-]/).at(-1).includes('.')) {
    return;
  } else {
    expression += value;
  }
  render();
}

keys.addEventListener('click', ({ target }) => {
  if (!target.matches('button')) return;
  const { value, action } = target.dataset;
  if (action === 'clear') expression = '';
  else if (action === 'delete') expression = expression.slice(0, -1);
  else if (action === 'equals') return calculate();
  else input(value);
  render();
});

document.addEventListener('keydown', ({ key }) => {
  if (/^[0-9.+*/%-]$/.test(key)) input(key);
  else if (key === 'Enter' || key === '=') calculate();
  else if (key === 'Backspace') { expression = expression.slice(0, -1); render(); }
  else if (key === 'Escape') { expression = ''; render(); }
});
