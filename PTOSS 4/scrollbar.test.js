const puppeteer = require('puppeteer');

describe('Teste de Scrollbar', () => {
let browser;
let page;

beforeAll(async () => {
browser = await puppeteer.launch();
page = await browser.newPage();
});

afterAll(async () => {
await browser.close();
});

test('Deve exibir a scrollbar quando o conteúdo exceder o container', async () => {
await page.setContent(`
<!DOCTYPE html>
<html lang="pt-BR">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Exemplo de Scrollbar</title>
    <style>
        .scroll-container {
            width: 300px;
            height: 200px;
            overflow: auto;
            border: 1px solid #ccc;
            padding: 10px;
        }

        .scroll-content {
            width: 600px;
            height: 400px;
            background-color: #f9f9f9;
        }

        .scroll-container::-webkit-scrollbar {
            width: 12px;
            height: 12px;
        }

        .scroll-container::-webkit-scrollbar-track {
            background: #f1f1f1;
        }

        .scroll-container::-webkit-scrollbar-thumb {
            background-color: #888;
            border-radius: 10px;
            border: 3px solid #f1f1f1;
        }

        .scroll-container::-webkit-scrollbar-thumb:hover {
            background-color: #555;
        }
    </style>
</head>

<body>
    <div class="scroll-container">
        <div class="scroll-content">
            <p>Este é um exemplo de conteúdo dentro de um contêiner que possui uma barra de rolagem.</p>
            <p>Adicione mais conteúdo aqui para ver a barra de rolagem em ação.</p>
            <p>Você pode rolar para ver mais conteúdo.</p>
        </div>
    </div>
</body>

</html>
`);

const container = await page.$('.scroll-container');
const boundingBox = await container.boundingBox();

// Verifica se a barra de rolagem horizontal está presente
const hasHorizontalScrollbar = await page.evaluate((container) => {
return container.scrollWidth > container.clientWidth;
}, container);
expect(hasHorizontalScrollbar).toBe(true);

// Verifica se a barra de rolagem vertical está presente
const hasVerticalScrollbar = await page.evaluate((container) => {
return container.scrollHeight > container.clientHeight;
}, container);
expect(hasVerticalScrollbar).toBe(true);
});
});