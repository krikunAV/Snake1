
/*while (window.isOpen())
    {
        // проверить все события окна, которые были вызваны с последней итерации цикла
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "запрос закрытия" событие: мы закрываем окно
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;*/

#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

int width = 20;
int height = 20;
int dotSize = 16;

int dir = 2;
int point = 3;

bool game = true;

struct Snake {
    int x, y;
} s[20];

struct Fruct
{
    int x, y;
} f;

void Tick() {
    for (int i = point; i > 0; i--) {
        s[i].x = s[i - 1].x;
        s[i].y = s[i - 1].y;
    }

    if (dir == 0)
        s[0].y += 1;
    if (dir == 1)
        s[0].x -= 1;
    if (dir == 2)
        s[0].x += 1;
    if (dir == 3)
        s[0].y -= 1;

    if (s[0].x > width)
        s[0].x = 0;
    if (s[0].x < 0)
        s[0].x = width;
    if (s[0].y > height)
        s[0].y = 0;
    if (s[0].y < 0)
        s[0].y = height;

    if ((s[0].x == f.x) && (s[0].y == f.y)) {
        point++;

        f.x = rand() % width;
        f.y = rand() % height;
    }

    for (int i = 1; i < point; i++)
        if ((s[0].x == s[i].x) && (s[0].y == s[i].y))
            game = false;
}

int main()
{
    srand(time(0));
    
    RenderWindow window(VideoMode(dotSize * width, dotSize * height), "Snake!");

   
    Texture sn;
    sn.loadFromFile("C:/Users/Александр/Desktop/start android/dot.png");
    Sprite snake(sn);
    
    Texture ap;
    ap.loadFromFile("C:/Users/Александр/Desktop/start android/apple.png");
    Sprite apple(ap);

    Texture go;
    go.loadFromFile("C:/Users/Александр/Desktop/start android/go.png");
    Sprite gameover(go);
    gameover.setPosition(0, 175);

    f.x = 10;
    f.y = 10;

    Clock clock;
    float timer = 0, delay = 0.1;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;
        
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
            dir = 1;
        if (Keyboard::isKeyPressed(Keyboard::Right))
            dir = 2;
        if (Keyboard::isKeyPressed(Keyboard::Up))
            dir = 3;
        if (Keyboard::isKeyPressed(Keyboard::Down))
            dir = 0;

        if (timer > delay && game) {
            timer = 0;
            Tick();
        }

        window.clear();
        
        

        for (int i = 0; i < point; i++) {
            if (i != 0)
                snake.setTextureRect(IntRect(0, 0, dotSize, dotSize));
            else
                snake.setTextureRect(IntRect(dir*dotSize, dotSize, dotSize, dotSize));

            if (!game && i == 1)
                snake.setTextureRect(IntRect(dir * dotSize, dotSize*2, dotSize, dotSize));

            snake.setPosition(s[i].x * dotSize, s[i].y * dotSize);
            window.draw(snake);
        }

        apple.setPosition(f.x * dotSize, f.y * dotSize);
        window.draw(apple);

        if (!game)
            window.draw(gameover);

        window.display();
    }

    return 0;
}