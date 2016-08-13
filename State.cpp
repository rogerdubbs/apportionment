// Copyright (c) 2016 Roger Dubbs
#include "State.h"

State::State(const Name& name, Population population)
    :m_name{name},
     m_population{population}
{
}

Name State::name() const
{
    return m_name;
}

Population State::population() const
{
    return m_population;
}
