//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2013      Mohammed Nafees  <nafees.technocool@gmail.com>
//

#include "GeoDataViewVolume.h"

#include "GeoDataTypes.h"

namespace Marble
{

class GeoDataViewVolumePrivate
{
public:
    GeoDataViewVolumePrivate();

    qreal m_leftFov;
    qreal m_rightFov;
    qreal m_bottomFov;
    qreal m_topFov;
    qreal m_near;
};

GeoDataViewVolumePrivate::GeoDataViewVolumePrivate() :
    m_leftFov(),
    m_rightFov(),
    m_bottomFov(),
    m_topFov(),
    m_near()
{
    // nothing to do
}

GeoDataViewVolume::GeoDataViewVolume() : d( new GeoDataViewVolumePrivate )
{
    // nothing to do
}

GeoDataViewVolume::GeoDataViewVolume( const Marble::GeoDataViewVolume &other ) :
    GeoDataObject(), d( new GeoDataViewVolumePrivate( *other.d ) )
{
    // nothing to do
}

GeoDataViewVolume &GeoDataViewVolume::operator=( const GeoDataViewVolume &other )
{
    GeoDataObject::operator=( other );
    *d = *other.d;
    return *this;
}

GeoDataViewVolume::~GeoDataViewVolume()
{
    delete d;
}

const char *GeoDataViewVolume::nodeType() const
{
    return GeoDataTypes::GeoDataViewVolumeType;
}

qreal GeoDataViewVolume::leftFov() const
{
    return d->m_leftFov;
}

void GeoDataViewVolume::setLeftFov( const qreal &leftFov )
{
    d->m_leftFov = leftFov;
}

qreal GeoDataViewVolume::rightFov() const
{
    return d->m_rightFov;
}

void GeoDataViewVolume::setRightFov( const qreal &rightFov )
{
    d->m_rightFov = rightFov;
}

qreal GeoDataViewVolume::bottomFov() const
{
    return d->m_bottomFov;
}

void GeoDataViewVolume::setBottomFov( const qreal &bottomFov )
{
    d->m_bottomFov = bottomFov;
}

qreal GeoDataViewVolume::topFov() const
{
    return d->m_topFov;
}

void GeoDataViewVolume::setTopFov( const qreal &topFov )
{
    d->m_topFov = topFov;
}

qreal GeoDataViewVolume::near() const
{
    return d->m_near;
}

void GeoDataViewVolume::setNear( const qreal &near )
{
    d->m_near = near;
}

}
