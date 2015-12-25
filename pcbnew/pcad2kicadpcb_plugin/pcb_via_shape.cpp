/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2007, 2008 Lubo Racko <developer@lura.sk>
 * Copyright (C) 2007, 2008, 2012 Alexander Lunev <al.lunev@yahoo.com>
 * Copyright (C) 2012 KiCad Developers, see CHANGELOG.TXT for contributors.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

/**
 * @file pcb_via_shape.cpp
 */

#include <wx/wx.h>
#include <wx/config.h>

#include <common/common.h>

#include <pcb_via_shape.h>

namespace PCAD2KICAD {

PCB_VIA_SHAPE::PCB_VIA_SHAPE( PCB_CALLBACKS*    aCallbacks,
                              BOARD*            aBoard ) : PCB_PAD_SHAPE( aCallbacks, aBoard )
{
}


PCB_VIA_SHAPE::~PCB_VIA_SHAPE()
{
}


void PCB_VIA_SHAPE::Parse( XNODE*       aNode,
                           wxString     aDefaultMeasurementUnit,
                           wxString     aActualConversion )
{
    XNODE*      lNode;
    wxString    str;
    long        num;

    lNode = FindNode( aNode, wxT( "viaShapeType" ) );

    if( lNode )
    {
        str = lNode->GetNodeContent();
        str.Trim( false );
        m_shape = str;
    }

    lNode = FindNode( aNode, wxT( "layerNumRef" ) );

    if( lNode )
    {
        lNode->GetNodeContent().ToLong( &num );
        m_PCadLayer = (int) num;
    }

    m_KiCadLayer = GetKiCadLayer();
    lNode = FindNode( aNode, wxT( "shapeWidth" ) );

    if( lNode )
        SetWidth( lNode->GetNodeContent(), aDefaultMeasurementUnit, &m_width, aActualConversion );

    lNode = FindNode( aNode, wxT( "shapeHeight" ) );

    if( lNode )
        SetWidth( lNode->GetNodeContent(), aDefaultMeasurementUnit, &m_height, aActualConversion );

}

} // namespace PCAD2KICAD
