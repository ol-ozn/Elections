#pragma once

class SelectionPolicy {
    public:
        virtual void select() = 0;
 };

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        void select();
 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
        void select();
 };