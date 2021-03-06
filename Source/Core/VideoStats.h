/*  Copyright (c) BAVC. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license that can
 *  be found in the License.html file in the root of the source tree.
 */

//---------------------------------------------------------------------------
#ifndef VideoStats_H
#define VideoStats_H

#include "Core/Core.h"
#include "Core/CommonStats.h"

#include <string>
#include <vector>
#include <stdint.h>
using namespace std;

struct AVFrame;

class VideoStats : public CommonStats
{
public:
    // Constructor / Destructor
    VideoStats(size_t FrameCount=0, double Duration=0, double Frequency=0);
    ~VideoStats();

    // External data
    void                        StatsFromExternalData(const string &Data);
    void                        StatsFromFrame(struct AVFrame* Frame, int Width, int Height);
    void                        TimeStampFromFrame(struct AVFrame* Frame, size_t FramePos);
    string                      StatsToCSV();
    string                      StatsToXML(int Width, int Height);

private:
};

#endif // Stats_H
