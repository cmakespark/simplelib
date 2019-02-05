#include "dog.h"
#include "dog_p.h"


Dog::Dog():
    d(new Impl())
{
}

Dog::~Dog()
{
}

int Dog::weight() const
{
    return d->m_weight;
}

void Dog::bark()
{
    d->m_barks++;
}

int Dog::numberOfBarks() const
{
    return d->m_barks;
}

Dog::Impl::Impl():
    m_weight(10),
    m_barks(0)
{}
