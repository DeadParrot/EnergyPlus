// EnergyPlus, Copyright (c) 1996-2019, The Board of Trustees of the University of Illinois,
// The Regents of the University of California, through Lawrence Berkeley National Laboratory
// (subject to receipt of any required approvals from the U.S. Dept. of Energy), Oak Ridge
// National Laboratory, managed by UT-Battelle, Alliance for Sustainable Energy, LLC, and other
// contributors. All rights reserved.
//
// NOTICE: This Software was developed under funding from the U.S. Department of Energy and the
// U.S. Government consequently retains certain rights. As such, the U.S. Government has been
// granted for itself and others acting on its behalf a paid-up, nonexclusive, irrevocable,
// worldwide license in the Software to reproduce, distribute copies to the public, prepare
// derivative works, and perform publicly and display publicly, and to permit others to do so.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted
// provided that the following conditions are met:
//
// (1) Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//
// (2) Redistributions in binary form must reproduce the above copyright notice, this list of
//     conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//
// (3) Neither the name of the University of California, Lawrence Berkeley National Laboratory,
//     the University of Illinois, U.S. Dept. of Energy nor the names of its contributors may be
//     used to endorse or promote products derived from this software without specific prior
//     written permission.
//
// (4) Use of EnergyPlus(TM) Name. If Licensee (i) distributes the software in stand-alone form
//     without changes from the version obtained under this License, or (ii) Licensee makes a
//     reference solely to the software portion of its product, Licensee must refer to the
//     software as "EnergyPlus version X" software, where "X" is the version number Licensee
//     obtained under this License and may not use a different name for the software. Except as
//     specifically required in this Section (4), Licensee shall not use in a company name, a
//     product name, in advertising, publicity, or other promotional activities any name, trade
//     name, trademark, logo, or other designation of "EnergyPlus", "E+", "e+" or confusingly
//     similar designation, without the U.S. Department of Energy's prior written consent.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

// EnergyPlus Headers
#include <EnergyPlus/DataPrecisionGlobals.hh>
#include <EnergyPlus/DataWindowEquivalentLayer.hh>

namespace EnergyPlus {

namespace DataWindowEquivalentLayer {
    // MODULE INFORMATION:
    //       AUTHOR         Bereket Nigusse, FSEC/UCF
    //       DATE WRITTEN   May 2013
    //       MODIFIED       na
    //       RE-ENGINEERED  na

    // PURPOSE OF THIS MODULE:
    // This data-only module for equivalent layer window model.

    // METHODOLOGY EMPLOYED:
    // na

    // REFERENCES:
    // na

    // OTHER NOTES:
    // na

    // Using/Aliasing
    using namespace DataPrecisionGlobals;

    // Data
    // CFSTY: Complex Fenestration System
    int const CFSMAXNL(6); // max # of glaze or shade layers
    // Long-wave (aka LW or thermal) layer properties
    // Short wave (aka SW or solar) layer properties
    // "black" room (no reflection)
    // Layer information

    // Gap Gas Properties
    // Gap information
    // Equivalent Layer Window Constructon
    // CFSLAYER: layer types
    int const ltyNONE(0);   // unused / empty layer
    int const ltyGLAZE(1);  // glazing layer i.e, purely specular
    int const ltyDRAPE(2);  // pleated drapes/curtains
    int const ltyROLLB(3);  // roller blind
    int const ltyVBHOR(4);  // venetian blinds - horizontal
    int const ltyVBVER(5);  // venetian blinds - vertical
    int const ltyINSCRN(6); // insect screen
    int const ltyROOM(7);   // indoor space and/or make no adjustment
    int const ltyGZS(8);    // glazing with spectral data (read from aux file)
    // index for solar arrays
    int const isDIFF(1);
    int const isBEAM(2);
    // Defined CFSLayers and CFSs
    int TotWinEquivLayerConstructs(0); // Number of constructions with Window equivalent Layer

    // Object Data
    CFSSWP SWP_ROOMBLK; // Solar reflectance, BEAM-BEAM, front | Solar reflectance, BEAM-BEAM, back | Solar transmittance, BEAM-BEAM, front | Solar
                        // transmittance, BEAM-BEAM, back | Solar reflectance, BEAM-DIFFUSE, front | Solar reflectance, BEAM-DIFFUSE, back | Solar
                        // transmittance, BEAM-DIFFUSE, front | Solar transmittance, BEAM-DIFFUSE, back | Solar reflectance, DIFFUSE-DIFFUSE, front |
                        // Solar reflectance, DIFFUSE-DIFFUSE, back | Solar transmittance, DIFFUSE-DIFFUSE
    Array1D<CFSLAYER> CFSLayers;
    Array1D<CFSTY> CFS;
    Array1D<CFSGAP> CFSGaps;

} // namespace DataWindowEquivalentLayer

} // namespace EnergyPlus
