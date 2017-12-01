#ifndef SONG_DEFINITIONS_H
#define SONG_DEFINITIONS_H

#include "Song.h"

namespace buzzer
{
/*
    void MaryHadALittleLamb(Song& song)
    {
        song.Reset();
        song.SetTempo(120);
        
        song.AddNote(kE4, kQuarter);
        song.AddNote(kD4, kQuarter);
        song.AddNote(kC4, kQuarter);
        song.AddNote(kD4, kQuarter);
        
        song.AddNote(kE4, kQuarter);
        song.AddNote(kE4, kQuarter);
        song.AddNote(kE4, kHalf);
    
        song.AddNote(kD4, kQuarter);
        song.AddNote(kD4, kQuarter);
        song.AddNote(kD4, kHalf);
    
        song.AddNote(kE4, kQuarter);
        song.AddNote(kG4, kQuarter);
        song.AddNote(kG4, kHalf);
    
        song.AddNote(kE4, kQuarter);
        song.AddNote(kD4, kQuarter);
        song.AddNote(kC4, kQuarter);
        song.AddNote(kD4, kQuarter);
    
        song.AddNote(kE4, kQuarter);
        song.AddNote(kE4, kQuarter);
        song.AddNote(kE4, kQuarter);
        song.AddNote(kE4, kQuarter);
    
        song.AddNote(kD4, kQuarter);
        song.AddNote(kD4, kQuarter);
        song.AddNote(kE4, kQuarter);
        song.AddNote(kD4, kQuarter);
    
        song.AddNote(kC4, kWhole);
    }

    void StarWars(Song& song)
    {
        song.Reset();
        song.SetTempo(132);

        song.AddNote(kD4, kEighthTriplet);
        song.AddNote(kD4, kEighthTriplet);
        song.AddNote(kD4, kEighthTriplet);

        song.AddNote(kG4, kHalf);
        song.AddNote(kD5, kHalf);

        song.AddNote(kC5, kEighthTriplet);
        song.AddNote(kB4, kEighthTriplet);
        song.AddNote(kA4, kEighthTriplet);

        song.AddNote(kG5, kHalf);
        song.AddNote(kD5, kQuarter);

        song.AddNote(kC5, kEighthTriplet);
        song.AddNote(kB4, kEighthTriplet);
        song.AddNote(kA4, kEighthTriplet);

        song.AddNote(kG5, kHalf);
        song.AddNote(kD5, kQuarter);

        song.AddNote(kC5, kEighthTriplet);
        song.AddNote(kB4, kEighthTriplet);
        song.AddNote(kC5, kEighthTriplet);

        song.AddNote(kA4, kHalf);

        song.AddNote(kD4, kEighthTriplet);
        song.AddNote(kD4, kEighthTriplet);
        song.AddNote(kD4, kEighthTriplet);

        song.AddNote(kG4, kHalf);
        song.AddNote(kD5, kHalf);

        song.AddNote(kC5, kEighthTriplet);
        song.AddNote(kB4, kEighthTriplet);
        song.AddNote(kA4, kEighthTriplet);

        song.AddNote(kG5, kHalf);
        song.AddNote(kD5, kQuarter);

        song.AddNote(kC5, kEighthTriplet);
        song.AddNote(kB4, kEighthTriplet);
        song.AddNote(kA4, kEighthTriplet);

        song.AddNote(kG5, kHalf);
        song.AddNote(kD5, kQuarter);

        song.AddNote(kC5, kEighthTriplet);
        song.AddNote(kB4, kEighthTriplet);
        song.AddNote(kC5, kEighthTriplet);

        song.AddNote(kA4, kHalf);

        song.AddNote(kD4, kDottedEighth);
        song.AddNote(kD4, kSixteenth);

        song.AddNote(kE4, kDottedQuarter);
        song.AddNote(kE4, kEighth);

        song.AddNote(kC5, kEighth);
        song.AddNote(kB4, kEighth);
        song.AddNote(kA4, kEighth);
        song.AddNote(kG4, kEighth);

        song.AddNote(kG4, kEighthTriplet);
        song.AddNote(kA4, kEighthTriplet);
        song.AddNote(kB4, kEighthTriplet);

        song.AddNote(kA4, kDottedEighth);
        song.AddNote(kE4, kSixteenth);
        song.AddNote(kF4Sharp, kQuarter);

        song.AddNote(kD4, kDottedEighth);
        song.AddNote(kD4, kSixteenth);

        song.AddNote(kE4, kDottedQuarter);
        song.AddNote(kE4, kEighth);

        song.AddNote(kC5, kEighth);
        song.AddNote(kB4, kEighth);
        song.AddNote(kA4, kEighth);
        song.AddNote(kG4, kEighth);

        song.AddNote(kD5, kDottedEighth);

        song.AddNote(kA4, kSixteenth);
        song.AddNote(kA4, kHalf);

        // Octave up
        song.AddNote(kD5, kDottedEighth);
        song.AddNote(kD5, kSixteenth);

        song.AddNote(kE5, kDottedQuarter);
        song.AddNote(kE5, kEighth);

        song.AddNote(kC6, kEighth);
        song.AddNote(kB5, kEighth);
        song.AddNote(kA5, kEighth);
        song.AddNote(kG5, kEighth);

        song.AddNote(kG5, kEighthTriplet);
        song.AddNote(kA5, kEighthTriplet);
        song.AddNote(kB5, kEighthTriplet);

        song.AddNote(kA5, kDottedEighth);
        song.AddNote(kE5, kSixteenth);
        song.AddNote(kF5Sharp, kQuarter);

        song.AddNote(kD5, kDottedEighth);
        song.AddNote(kD5, kSixteenth);

        // Descent
        song.AddNote(kG5, kDottedEighth);
        song.AddNote(kF5, kSixteenth);
        song.AddNote(kD5Sharp, kDottedEighth);
        song.AddNote(kD5, kSixteenth);
        song.AddNote(kC4, kDottedEighth);
        song.AddNote(kA4Sharp, kSixteenth);
        song.AddNote(kA4, kDottedEighth);
        song.AddNote(kG4, kSixteenth);

        song.AddNote(kD5, kDottedHalf);
    }
    */

    void Valkyries(Song& song)
    {
        song.Reset();
        song.SetTempo(132);

        song.AddNote(kF4Sharp, kEighth);

        song.AddNote(kB4, kDottedEighth);
        song.AddNote(kF4Sharp, kSixteenth);
        song.AddNote(kB4, kEighth);

        song.AddNote(kD5, kDottedQuarter);
        song.AddNote(kB4, kDottedQuarter);

        song.AddNote(kD5, kDottedEighth);
        song.AddNote(kB4, kSixteenth);
        song.AddNote(kD5, kEighth);

        song.AddNote(kF5Sharp, kDottedQuarter);
        song.AddNote(kD5, kDottedQuarter);

        song.AddNote(kF5Sharp, kDottedEighth);
        song.AddNote(kD5, kSixteenth);
        song.AddNote(kF5Sharp, kEighth);

        song.AddNote(kA5, kDottedQuarter);
        song.AddNote(kA4, kDottedQuarter);

        song.AddNote(kD5, kDottedEighth);
        song.AddNote(kA4, kSixteenth);
        song.AddNote(kD5, kEighth);

        song.AddNote(kF5Sharp, kDottedHalf);

        // Repeat 
        song.AddNote(kA4, kEighth);
        
        song.AddNote(kD5, kDottedEighth);
        song.AddNote(kA4, kSixteenth);
        song.AddNote(kD5, kEighth);

        song.AddNote(kF5Sharp, kDottedQuarter);
        song.AddNote(kD5, kDottedQuarter);

        song.AddNote(kF5Sharp, kDottedEighth);
        song.AddNote(kD5, kSixteenth);
        song.AddNote(kF5Sharp, kEighth);

        song.AddNote(kA5, kDottedQuarter);
        song.AddNote(kF5Sharp, kDottedQuarter);

        song.AddNote(kA5, kDottedEighth);
        song.AddNote(kF5Sharp, kSixteenth);
        song.AddNote(kA5, kEighth);

        song.AddNote(kC6Sharp, kDottedQuarter);
        song.AddNote(kC5Sharp, kDottedQuarter);

        song.AddNote(kF5Sharp, kDottedEighth);
        song.AddNote(kC5Sharp, kSixteenth);
        song.AddNote(kF5Sharp, kEighth);

        song.AddNote(kA5Sharp, kDottedHalf);
    }
    /*

    void SongOfTime(Song& song)
    {
        song.Reset();
        song.SetTempo(120);

        song.AddNote(kA4, kQuarter);
        song.AddNote(kD4, kHalf);

        song.AddNote(kF4, kQuarter);
        song.AddNote(kA4, kQuarter);
        song.AddNote(kD4, kHalf);

        song.AddNote(kF4, kQuarter);
        song.AddNote(kA4, kEighth);
        song.AddNote(kC5, kEighth);
        song.AddNote(kB4, kQuarter);

        song.AddNote(kG4, kQuarter);
        song.AddNote(kF4, kEighth);
        song.AddNote(kG4, kEighth);
        song.AddNote(kA4, kQuarter);

        song.AddNote(kD4, kQuarter);
        song.AddNote(kC4, kEighth);
        song.AddNote(kE4, kEighth);
        song.AddNote(kD4, kWhole);
    }
    
    void RouteOne(Song& song)
    {
        song.Reset();
        song.SetTempo(128);

        song.AddNote(kD5, kSixteenth);
        song.AddNote(kE5, kSixteenth);
        song.AddNote(kF5Sharp, kEighth);
        song.AddNote(kF5Sharp, kEighth);
        song.AddNote(kF5Sharp, kEighth);

        song.AddNote(kD5, kSixteenth);
        song.AddNote(kE5, kSixteenth);
        song.AddNote(kF5Sharp, kEighth);
        song.AddNote(kF5Sharp, kEighth);
        song.AddNote(kF5Sharp, kEighth);

        song.AddNote(kD5, kSixteenth);
        song.AddNote(kE5, kSixteenth);
        song.AddNote(kF5Sharp, kEighth);
        song.AddNote(kF5Sharp, kEighth);
        song.AddNote(kG5, kDottedEighth);
        song.AddNote(kF5Sharp, kSixteenth);
        song.AddNote(kE5, kDottedQuarter);

        //asdasd
        song.AddNote(kC5Sharp, kSixteenth);
        song.AddNote(kD5, kSixteenth);
        song.AddNote(kE5, kEighth);
        song.AddNote(kE5, kEighth);
        song.AddNote(kE5, kEighth);

        song.AddNote(kC5Sharp, kSixteenth);
        song.AddNote(kD5, kSixteenth);
        song.AddNote(kE5, kEighth);
        song.AddNote(kE5, kEighth);
        song.AddNote(kE5, kEighth);

        song.AddNote(kC5Sharp, kSixteenth);
        song.AddNote(kD5, kSixteenth);
        song.AddNote(kE5, kEighth);
        song.AddNote(kE5, kEighth);

        song.AddNote(kF5Sharp, kSixteenth);
        song.AddNote(kE5, kSixteenth);
        song.AddNote(kE5, kSixteenth);
        song.AddNote(kF5Sharp, kSixteenth);
        song.AddNote(kD5, kQuarter);
        song.AddNote(kF5Sharp, kEighth);

        //asdasd
        
        song.AddNote(kD5, kSixteenth);
        song.AddNote(kE5, kSixteenth);
        song.AddNote(kF5Sharp, kEighth);
        song.AddNote(kF5Sharp, kEighth);
        song.AddNote(kF5Sharp, kEighth);

        song.AddNote(kD5, kSixteenth);
        song.AddNote(kE5, kSixteenth);
        song.AddNote(kF5Sharp, kEighth);
        song.AddNote(kF5Sharp, kEighth);
        song.AddNote(kF5Sharp, kEighth);

        song.AddNote(kD5, kSixteenth);
        song.AddNote(kE5, kSixteenth);
        song.AddNote(kF5Sharp, kEighth);
        song.AddNote(kF5Sharp, kEighth);
        song.AddNote(kG5, kDottedEighth);
        song.AddNote(kF5Sharp, kSixteenth);
        song.AddNote(kE5, kDottedQuarter);

        // asdasd

        song.AddNote(kC5Sharp, kSixteenth);
        song.AddNote(kD5, kSixteenth);

        song.AddNote(kE5, kEighth);
        song.AddNote(kG5, kEighth);
        song.AddNote(kF5Sharp, kEighth);
        song.AddNote(kE5, kEighth);
        song.AddNote(kD5, kEighth);
        song.AddNote(kC5Sharp, kEighth);
        song.AddNote(kB4, kEighth);
        song.AddNote(kC5, kEighth);
        
        song.AddNote(kB5, kQuarter);

        song.AddNote(kE5, kSixteenth);
        song.AddNote(kB4, kSixteenth);
        song.AddNote(kA4, kSixteenth);
        song.AddNote(kC5Sharp, kSixteenth);

        song.AddNote(kF5Sharp, kEighth);
        song.AddNote(kA4, kEighth);
        song.AddNote(kA4, kEighth);

        // asdasd

        song.AddNote(kF5Sharp, kSixteenth);
        song.AddNote(kG5, kSixteenth);

        song.AddNote(kA5, kEighth);
        song.AddNote(kA5, kEighth);
        song.AddNote(kF5Sharp, kEighth);
        song.AddNote(kD5, kEighth);

        song.AddNote(kD6, kEighth);
        song.AddNote(kC6Sharp, kEighth);
        song.AddNote(kB6, kEighth);
        song.AddNote(kC6Sharp, kEighth);

        song.AddNote(kA5, kEighth);
        song.AddNote(kF5Sharp, kEighth);
        song.AddNote(kD5, kDottedEighth);
        song.AddNote(kF5Sharp, kSixteenth);

        song.AddNote(kE5, kDottedQuarter);

        song.AddNote(kF5Sharp, kSixteenth);
        song.AddNote(kG5, kSixteenth);

        song.AddNote(kA5, kEighth);
        song.AddNote(kA5, kEighth);
        song.AddNote(kF5Sharp, kEighth);
        song.AddNote(kA5, kEighth);

        song.AddNote(kD6, kEighth);
        song.AddNote(kC6Sharp, kEighth);
        song.AddNote(kA5, kDottedEighth);
        song.AddNote(kG5, kSixteenth);

        song.AddNote(kA5, kEighth);
        song.AddNote(kD6, kEighth);
        song.AddNote(kC6Sharp, kEighth);
        song.AddNote(kE6, kEighth);

        song.AddNote(kD6, kQuarter);
    }
    */
}

#endif