#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class DecisionTree {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        if (x[1] <= 2.549999952316284) {
                            return 1;
                        }

                        else {
                            if (x[0] <= 7.349999904632568) {
                                return 1;
                            }

                            else {
                                if (x[0] <= 8.650000095367432) {
                                    if (x[2] <= 27.25) {
                                        return 1;
                                    }

                                    else {
                                        if (x[2] <= 34.5) {
                                            if (x[0] <= 8.100000143051147) {
                                                return 0;
                                            }

                                            else {
                                                if (x[1] <= 3.899999976158142) {
                                                    return 0;
                                                }

                                                else {
                                                    return 1;
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 2.799999952316284) {
                                                return 0;
                                            }

                                            else {
                                                return 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[2] <= 26.600000381469727) {
                                        if (x[2] <= 25.100000381469727) {
                                            return 1;
                                        }

                                        else {
                                            return 0;
                                        }
                                    }

                                    else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }

                protected:
                };
            }
        }
    }