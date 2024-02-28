#include "../include/bear.hpp"
#include "../include/elf.hpp"
#include "../include/thug.hpp"

Bear::Bear(int x, int y) : NPC(BearType, x, y) {}
Bear::Bear(std::istream &is) : NPC(BearType, is) {}

bool Bear::accept(std::shared_ptr<NPC> visitor)
{
    return visitor->fight(std::shared_ptr<Bear>(this, [](Bear *) {}));
}

void Bear::print()
{
    std::cout << *this;
}

bool Bear::fight(std::shared_ptr<Bear> other)
{
    fight_notify(other, false);
    return false;
}

bool Bear::fight(std::shared_ptr<Elf> other)
{
    fight_notify(other, true);
    return false;
}

bool Bear::fight(std::shared_ptr<Thug> other)
{
    fight_notify(other, false);
    return false;
}

void Bear::save(std::ostream &os)
{
    os << BearType << std::endl;
    NPC::save(os);
}

std::ostream &operator<<(std::ostream &os, Bear &Bear)
{
    os << "Bear: " << *static_cast<NPC *>(&Bear) << std::endl;
    return os;
}