const itemInput = document.getElementById('itemInput');
const addBtn = document.getElementById('addBtn');
const myList = document.getElementById('myList');

function addItem() {
    // берём текст из поля ввода и убираем лишние пробелы по краям
    const text = itemInput.value.trim();

    // если поле пустое, ничего не добавляем и выходим из функции
    if (text === '') {
        return;
    }

    // создаем новый элемент
    const newItem = document.createElement('li');
    // записываем в него введенный текст
    newItem.textContent = text;

    // добавляем созданный <li> в конец списка <ul>
    myList.appendChild(newItem);

    // очищаем поле ввода для следующего элемента
    itemInput.value = '';
}

// вешаем обработчик клика на кнопку
addBtn.addEventListener('click', addItem);