#include "Symbol.h"

#include "../Node/BaseNode.h"

Symbol::Symbol()
{
    this->idName = "";
    this->idType = SymbolType::integer;
    this->width = 4;
    this->value = "0";
    this->isUsed = false;
}

Symbol::Symbol(std::string name, SymbolType type, int width,
               std::string init_value)
{
    this->idName = name;
    this->idType = type;
    this->width = width;
    this->value = init_value;
    this->isUsed = false;
}
void Symbol::showSymbolInfor()
{
    std::cout << "Symbol Name: " << this->idName << "\tSymbol Addr: " << this
              << "\tSymbol Value: " << this->value
              << "\tpointer Addr: " << this->pointerAddr
              << "\twitdth: " << this->width
              << "\tSymbol Type: " << static_cast<int>(this->idType)
              << "\tisUsed: " << this->isUsed << std::endl;
}

SymbolArea::SymbolArea()
{
    this->parentArea = nullptr;
    this->firstChildArea = nullptr;
    this->firstBrotherArea = nullptr;
    this->total_offset = 0;
    this->symbolNumber = 0;
    this->baseArea = nullptr;
}

Symbol *SymbolArea::findSymbolLocally(std::string name)
{
    // printf("findSymbolLocally\n");
    if (this->SymbolMap.find(name) != this->SymbolMap.end())
    {
        return this->SymbolMap[name];
    }
    else
    {
        return nullptr;
    }
}

Symbol *SymbolArea::findSymbolGlobally(std::string name)
{
    SymbolArea *area = this;
    int cnt = 0;
    while (area)
    {
        for (auto i : area->SymbolMap)
        {
            printf("AAA:%s\n", i.first.c_str());
        }
        cnt++;
        if (area->SymbolMap.find(name) != area->SymbolMap.end())
        {
            return area->SymbolMap[name];
        }
        area = area->getParentArea();
    }
    printf("finddeep：%d\n", cnt);
    // std::cout << name << std::endl;
    printf("Variable %s Undefined!\n", name.c_str());
    exit(1);
}

bool SymbolArea::addSymbol(Symbol *symbol)
{
    if (this->findSymbolLocally(symbol->getIdName()) != nullptr)
    {
        return false;
    }
    this->SymbolMap[symbol->getIdName()] = symbol;
    this->symbolNumber++;
    printf("nishiadsa:%s\n", symbol->getIdName().c_str());
    return true;
}

SymbolArea *SymbolArea::getParentArea() { return this->parentArea; }

SymbolArea *SymbolArea::getFirstChildArea() { return this->firstChildArea; }

SymbolArea *SymbolArea::getFirstBrotherArea() { return this->firstBrotherArea; }

SymbolArea *SymbolArea::getBaseArea() { return this->baseArea; }

int SymbolArea::getSymbolNumber() { return this->symbolNumber; }

int SymbolArea::getOffset() { return this->total_offset; }

int SymbolArea::setOffset(int offset)
{
    this->total_offset = offset;
    return this->total_offset;
}

void SymbolArea::setParentArea(SymbolArea *parentArea)
{
    this->parentArea = parentArea;
}

void SymbolArea::setFirstBrotherArea(SymbolArea *brotherArea)
{
    this->firstBrotherArea = brotherArea;
}

SymbolArea *SymbolArea::addNewChildArea()
{
    SymbolArea *newArea = new SymbolArea();
    newArea->setParentArea(this);
    printf("begin add area\n");
    if (this->firstChildArea == nullptr)
    {
        printf("add first area\n");

        this->firstChildArea = newArea;
    }
    else
    {
        printf("add not first area\n");

        SymbolArea *temp = this->firstChildArea;
        while (temp->getFirstBrotherArea() != nullptr)
        {
            temp = temp->getFirstBrotherArea();
        }
        temp->setFirstBrotherArea(newArea);
    }
    return newArea;
}

void SymbolArea::showSymbolArea()
{
    std::cout << "Symbol Area: " << this << std::endl;
    for (auto it = this->SymbolMap.begin(); it != this->SymbolMap.end(); it++)
    {
        it->second->showSymbolInfor();
    }
    std::cout << std::endl;
}
