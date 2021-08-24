
/*
 *
 *  * Copyright (c) Crio.Do 2019. All rights reserved
 *
 */

package com.crio.qeats.services;

import com.crio.qeats.dto.Restaurant;
import com.crio.qeats.exchanges.GetRestaurantsRequest;
import com.crio.qeats.exchanges.GetRestaurantsResponse;
import com.crio.qeats.models.RestaurantEntity;
import com.crio.qeats.repositoryservices.RestaurantRepositoryService;
import com.crio.qeats.repositoryservices.RestaurantRepositoryServiceDummyImpl;

import java.time.LocalTime;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;


import lombok.extern.log4j.Log4j2;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;



@Service
@Log4j2
public class RestaurantServiceImpl implements RestaurantService {

  private final Double peakHoursServingRadiusInKms = 3.0;
  private final Double normalHoursServingRadiusInKms = 5.0;
  @Autowired
  private RestaurantRepositoryService restaurantRepositoryService;


  //  CRIO_TASK_MODULE_RESTAURANTSAPI - Implement findAllRestaurantsCloseby.
  // Check RestaurantService.java file for the interface contract.
  @Override
    public GetRestaurantsResponse findAllRestaurantsCloseBy(GetRestaurantsRequest 
      getRestaurantsRequest, LocalTime currentTime) {
    List<Restaurant> restaurant;
    int h = currentTime.getHour();
    int m = currentTime.getMinute();
    if ((h >= 8 && h <= 9) || (h == 10 && m == 0) || (h == 13) || (h == 14 && m == 0) 
          || (h >= 19 && h <= 20) || (h == 21 && m == 0)) {
      restaurant = restaurantRepositoryService.findAllRestaurantsCloseBy(
          getRestaurantsRequest.getLatitude(), getRestaurantsRequest.getLongitude(), 
          currentTime, peakHoursServingRadiusInKms);
    } else {
      restaurant = restaurantRepositoryService.findAllRestaurantsCloseBy(
        getRestaurantsRequest.getLatitude(), getRestaurantsRequest.getLongitude(), 
        currentTime, normalHoursServingRadiusInKms);
    }
    GetRestaurantsResponse response = new GetRestaurantsResponse(restaurant);
    //log.info(response);
    return response;
  }



  // TODO: CRIO_TASK_MODULE_RESTAURANTSEARCH
  // Implement findRestaurantsBySearchQuery. The request object has the search string.
  // We have to combine results from multiple sources:
  // 1. Restaurants by name (exact and inexact)
  // 2. Restaurants by cuisines (also called attributes)
  // 3. Restaurants by food items it serves
  // 4. Restaurants by food item attributes (spicy, sweet, etc)
  // Remember, a restaurant must be present only once in the resulting list.
  // Check RestaurantService.java file for the interface contract.
  /**
   * Get the restaurants by processing the query.
   * -Ordering rules
   *  1) Restaurant name
   *    - exact matches first
   *    - partial matches second
   *  2) Restaurant attributes
   *    - partial and full matches in any order
   *  3) Item name
   *    - exact matches first
   *    - partial matches second
   *  4) Item attributes
   *    - partial and full matches in any order
   * - For peak hours: 8AM - 10AM, 1PM-2PM, 7PM-9PM
   * - service radius is 3KMs.
   * - All other times, serving radius is 5KMs.
   * - If there are no restaurants, return empty list of restaurants.
   * @param getRestaurantsRequest valid lat/long and searchFor
   * @return GetRestaurantsResponse object containing a list of open restaurants or an
   *     empty list if none fits the criteria.
   */

  @Override
  public GetRestaurantsResponse findRestaurantsBySearchQuery(GetRestaurantsRequest getRestaurantsRequest,
      LocalTime currentTime) {
    // TODO Auto-generated method stub

    List<Restaurant> restaurant = new ArrayList<>();
    List<Restaurant> restaurantList ;
    // List<Restaurant> availableRestaurant;
    HashSet<Restaurant> set=new HashSet();  

        Double latitude = getRestaurantsRequest.getLatitude();
        Double longitude = getRestaurantsRequest.getLongitude();
        String searchString = getRestaurantsRequest.getSearchFor();
        
        // GetRestaurantsResponse getRestaurantsResponse =  findAllRestaurantsCloseBy(getRestaurantsRequest,currentTime);
        // availableRestaurant = getRestaurantsResponse.getRestaurants();

        // for(Restaurant restaurants : availableRestaurant){
        //   set.add(restaurants);
        // }

        if(searchString.equals("")){
          return  new GetRestaurantsResponse(restaurant);
        }


        int h = currentTime.getHour();
        int m = currentTime.getMinute();
        if ((h >= 8 && h <= 9) || (h == 10 && m == 0) || (h == 13) || (h == 14 && m == 0) 
              || (h >= 19 && h <= 20) || (h == 21 && m == 0)) {


        restaurantList = restaurantRepositoryService.findRestaurantsByName(latitude, longitude, searchString, currentTime, peakHoursServingRadiusInKms);

        // System.out.println("chk1");
        //   System.out.println(restaurantList.get(0));


        for(Restaurant restaurants : restaurantList){
          set.add(restaurants);
            
        }

        restaurantList = restaurantRepositoryService.findRestaurantsByNameNotExact(latitude, longitude, searchString, currentTime, peakHoursServingRadiusInKms);

        for(Restaurant restaurants : restaurantList){
          set.add(restaurants);
            
        }

        restaurantList = restaurantRepositoryService.findRestaurantsByAttributes(latitude, longitude, searchString, currentTime, peakHoursServingRadiusInKms);

        for(Restaurant restaurants : restaurantList){
          set.add(restaurants);
            
        }



        restaurantList = restaurantRepositoryService.findRestaurantsByItemName(latitude, longitude, searchString, currentTime, peakHoursServingRadiusInKms);

        for(Restaurant restaurants : restaurantList){
          set.add(restaurants);
            
        }


        restaurantList = restaurantRepositoryService.findRestaurantsByItemAttributes(latitude, longitude, searchString, currentTime, peakHoursServingRadiusInKms);

        

        for(Restaurant restaurants : restaurantList){
          set.add(restaurants);
            
        }
        
        } else {


            restaurantList = restaurantRepositoryService.findRestaurantsByName(latitude, longitude, searchString, currentTime, normalHoursServingRadiusInKms);

            // System.out.println("chk1");
            //   System.out.println(restaurantList.get(0));


            for(Restaurant restaurants : restaurantList){
              set.add(restaurants);
                
            }

            restaurantList = restaurantRepositoryService.findRestaurantsByNameNotExact(latitude, longitude, searchString, currentTime, normalHoursServingRadiusInKms);

            for(Restaurant restaurants : restaurantList){
              set.add(restaurants);
                
            }

            restaurantList = restaurantRepositoryService.findRestaurantsByAttributes(latitude, longitude, searchString, currentTime, normalHoursServingRadiusInKms);

            for(Restaurant restaurants : restaurantList){
              set.add(restaurants);
                
            }



            restaurantList = restaurantRepositoryService.findRestaurantsByItemName(latitude, longitude, searchString, currentTime, normalHoursServingRadiusInKms);

            for(Restaurant restaurants : restaurantList){
              set.add(restaurants);
                
            }


            restaurantList = restaurantRepositoryService.findRestaurantsByItemAttributes(latitude, longitude, searchString, currentTime, normalHoursServingRadiusInKms);

            

            for(Restaurant restaurants : restaurantList){
              set.add(restaurants);
                
            }
          
     }

       
       

        Iterator<Restaurant> i=set.iterator();  
        while(i.hasNext())  
        {  
           System.out.println("i.hahnaext()....");
           System.out.println(i.next());
          restaurant.add(i.next());  
        }  


        // System.out.println("chk2");
        // System.out.println(restaurant.get(0));

        GetRestaurantsResponse response = new GetRestaurantsResponse(restaurant);
        // System.out.println("chk3");
        // System.out.println("response.getRestaurants().get(2).getRestaurantId() " + response.getRestaurants().get(0).getRestaurantId());
    return response;
  }


}

