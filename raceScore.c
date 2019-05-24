//
// Created by klonek on 22.05.19.
//
#include "raceScore.h"

RaceScore *addScore(RaceScore *list, char *raceName, char *date, char *time, int position, int differenceInPosition) {
   RaceScore *tmp = (RaceScore *) malloc(sizeof(RaceScore));
   tmp->next = NULL;
   tmp->raceName = raceName;
   tmp->date = date;
   tmp->time = time;
   tmp->position = position;
   tmp->differenceInPosition = differenceInPosition;
   if(list != NULL){
      tmp->next=list;
      list= tmp;
      return list;
   }  else{
      list = tmp;
      return list;
   }
};

void deleteScores(RaceScore *list) {

while(list!=NULL){
   RaceScore *tmp;
   tmp = list;
   list=list->next;
   free(tmp);
}

};