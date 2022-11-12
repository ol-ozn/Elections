#pragma once

class SelectionPolicy {
    public:
        virtual void select() = 0;
 };

class MandatesSelectionPolicy: public SelectionPolicy{ };

class EdgeWeightSelectionPolicy: public SelectionPolicy{ };