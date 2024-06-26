//###########################################################################
// This file is part of LImA, a Library for Image Acquisition
//
// Copyright (C) : 2009-2011
// European Synchrotron Radiation Facility
// BP 220, Grenoble 38043
// FRANCE
//
// This is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//###########################################################################
#ifndef PRINCETONROICTRLOBJ_H
#define PRINCETONROICTRLOBJ_H

#include "PrincetonCompatibility.h"

#include "lima/HwRoiCtrlObj.h"
#include "PrincetonDetInfoCtrlObj.h"
#include "PrincetonBinCtrlObj.h"


namespace lima
{
  namespace Princeton
  {
    class PRINCETON_EXPORT RoiCtrlObj : public HwRoiCtrlObj
    {
      DEB_CLASS_NAMESPC(DebModCamera,"RoiCtrlObj","Princeton");
    public:
      RoiCtrlObj(PicamHandle cam,BinCtrlObj&);
      virtual ~RoiCtrlObj();

      virtual void setRoi(const Roi& set_roi);
      virtual void getRoi(Roi& hw_roi);
      virtual void checkRoi(const Roi& set_roi, Roi& hw_roi);
    private:
      PicamHandle	m_cam;
      Roi		m_roi;
      piint		m_rows;
      piint		m_columns;
      PicamRoisConstraintRulesMask m_rules;
      BinCtrlObj&	m_bin;
    };
  } // namespace Princeton
} // namespace lima

#endif // PRINCETONROICTRLOBJ_H
