#include <iostream>
#include <string>

class Ring
{
protected:
    double m_weight;
    double m_price;
public:
    Ring(double weight, double price) : m_weight(weight), m_price(price) {}
    virtual std::string showRing() = 0;
    virtual ~Ring() {};
};

class Gold : public Ring
{
protected:
    const double gold_nazenka;
public:
    Gold(double weight, double price) : Ring(weight, price), gold_nazenka(0.05) {}
    double costRing()
    {
        return m_price * gold_nazenka + m_price;
    }
    std::string showRing()
    {
        std::string str{};
        str += "Материал кольца: Золото\n";
        str += "Bec кольца: " + std::to_string(m_weight) + '\n';
        str += "Цена кольца: " + std::to_string(costRing()) + '\n';
        return str;
    }
};

class StoneRing : public Gold
{
protected:
    double m_stone_price;
public:
    StoneRing(double weight, double price, double stone_price) : Gold(weight, price), m_stone_price(stone_price) {}
    std::string showRing()
    {
        std::string str{};
        str += "Материал кольца: Золото\n";
        str += "Наличие камня: true\n";
        str += "Bec кольца: " + std::to_string(m_weight) + '\n';
        str += "Цена кольца: " + std::to_string(m_price + m_stone_price) + '\n';
        return str;
    }
};

class Silver : public Ring
{
protected:
    const double silver_nazenka = 0.1;
public:
    Silver(double weight, double price) : Ring(weight, price) {}
    std::string showRing()
    {
        std::string str{};
        str += "Материал кольца: Серебро\n";
        str += "Bec кольца: " + std::to_string(m_weight) + '\n';
        str += "Цена кольца: " + std::to_string(m_price + m_price * silver_nazenka) + '\n';
        return str;
    }
};

std::string f(Ring*& obj)
{
    std::string str = obj->showRing();
    return str;
}

int main()
{
    Ring* rings[4];
    rings[0] = new Silver(2, 2000);
    rings[1] = new Silver(1, 1000);
    rings[2] = new StoneRing(3, 3000, 50);
    rings[3] = new Gold(1, 3000);

    for(int i = 0; i < 4; ++i)
    {
        std::cout << f(rings[i]);
        std::cout << '\n';
    }
    return 0;
}