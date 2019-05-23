//
// Created by klonek on 22.05.19.
//
#include "raceScore.h"

struct RaceScore *addScore(struct RaceScore *list,  char * raceName, char * date, char * time, int position, int differenceInPosition){
   struct RaceScore *tmp = (struct RaceScore*)malloc(sizeof(struct RaceScore));
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
void deleteScores(struct RaceScore *list){
   struct RaceScore *tmp;
while(list!=NULL){
   tmp = list;
   list=list->next;
   free(tmp);
}

};