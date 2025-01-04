1. Rider
2. Driver/Cabs
3. Riber -> create a Trip
4. Driver Matching
5. Pricing
6. RiderManager (manages all riders)

   - singleton (we want single instance of RiderManager)

7. DriverManager (singleton class take cares of all drivers)
8. Rider class
9. Driver class
10. RiderManager <>---- aggregation ---- Rider (Rider exists without Manager)
11. DriveManager <>---- aggregation ---- Driver (same)
12. Trip class (when it is created?)

    - will be created when request comes
    - stores all info about the trip

13. what strategy/algorithm to use to macth drvers ?? (Nearest one, based on driver or rider rating, lowest price, ....)

    - we are going to support bunch of algorithms/strategies.
    - design pattern: Strategy Design Pattern
    - DriverMatchingStrategy Interface - match drivers (least ETA, ) classes
    - PriceMatchingStrategy Interface - calculate price (default, rating based, ...) classes
    - StrategyManager class(singleton) - what strategy to use for driver and price
    - since we are not going to share complete info about Trip to StrategyManager , but only few data. The class responsible to share data is TripMeataData.

14. How trip is getting created?
    - TripManager class(singleton) - manages TripMetaData and Trip
    - composition relations
    - Trip and TripMeataData could not exits with out TripManager
