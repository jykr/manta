// -*- mode: c++; indent-tabs-mode: nil; -*-
//
// Manta
// Copyright (c) 2013-2015 Illumina, Inc.
//
// This software is provided under the terms and conditions of the
// Illumina Open Source Software License 1.
//
// You should have received a copy of the Illumina Open Source
// Software License 1 along with this program. If not, see
// <https://github.com/sequencing/licenses/>
//

/// \author Chris Saunders
///

#pragma once

#include "sam_util.hh"


struct bam_dumper
{
    bam_dumper(const char* filename,
               const bam_header_t* header);

    ~bam_dumper()
    {
        if (NULL != _bfp) samclose(_bfp);
    }

    void
    put_record(const bam1_t* brec)
    {
        samwrite(_bfp,brec);
    }

private:
    samfile_t* _bfp;
};
