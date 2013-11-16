//
//  NodeBehavior.h
//  mm
//
//  Created by Riemer van Rozen on 10/9/13.
//  Copyright (c) 2013 Riemer van Rozen. All rights reserved.
//

#ifndef __mm__NodeBehavior__
#define __mm__NodeBehavior__

namespace MM
{
  class Transition;
  class Instance;
  class NodeBehavior : public Recyclable
  {
  public:
    typedef enum __IO
    {
      IO_ERROR,
      IO_PRIVATE,
      IO_IN,
      IO_OUT,
      IO_INOUT
    } IO;
    
    typedef enum __When
    {
      WHEN_ERROR,
      WHEN_PASSIVE,
      WHEN_AUTO,
      WHEN_USER,
      WHEN_START
    } When;
    
    typedef enum __Act
    {
      ACT_ERROR,
      ACT_PULL,
      ACT_PUSH
    } Act;
    
    typedef enum __How
    {
      HOW_ERROR,
      HOW_ANY,
      HOW_ALL
    } How;
    
    static const MM::CHAR * IO_STR[];
    static const MM::CHAR * WHEN_STR[];
    static const MM::CHAR * ACT_STR[];
    static const MM::CHAR * HOW_STR[];
    
    static const MM::UINT32 IO_LEN[];
    static const MM::UINT32 WHEN_LEN[];
    static const MM::UINT32 ACT_LEN[];
    static const MM::UINT32 HOW_LEN[];
    
  private:
    MM::NodeBehavior::IO io;
    MM::NodeBehavior::When when;
    MM::NodeBehavior::Act act;
    MM::NodeBehavior::How how;
  protected:
    NodeBehavior(MM::NodeBehavior::IO io,
                 MM::NodeBehavior::When when,
                 MM::NodeBehavior::Act act,
                 MM::NodeBehavior::How how);
  public:
    virtual ~NodeBehavior();
    MM::VOID recycle(MM::Recycler * r);
    
    virtual MM::TID getTypeId();
    virtual MM::BOOLEAN instanceof(MM::TID tid);
    
    MM::NodeBehavior::IO getIO();
    MM::NodeBehavior::When getWhen();
    MM::NodeBehavior::Act getAct();
    MM::NodeBehavior::How getHow();
    
    virtual MM::UINT32 getCreateMessage() = 0;
    virtual MM::UINT32 getUpdateMessage() = 0;
    virtual MM::UINT32 getDeleteMessage() = 0;
    
    MM::VOID setIO(MM::NodeBehavior::IO io);
    MM::VOID setWhen(MM::NodeBehavior::When when);
    MM::VOID setAct(MM::NodeBehavior::Act act);
    MM::VOID setHow(MM::NodeBehavior::How how);    
    
    MM::BOOLEAN conformsTo(MM::NodeBehavior::IO direction);
    
    //instance manipulation during transitions
    virtual MM::VOID add(MM::Instance * i,
                         MM::Node * n,
                         MM::UINT32 amount) = 0;
    virtual MM::VOID sub(MM::Instance * i,
                         MM::Node * n,
                         MM::UINT32 amount) = 0;
    virtual MM::UINT32 getCapacity(MM::Instance * i,
                                   MM::Node * n) = 0;
    virtual MM::UINT32 getResources(MM::Instance * i,
                                    MM::Node * n) = 0;
    virtual MM::BOOLEAN hasCapacity(MM::Instance * i,
                                    MM::Node * n,
                                    MM::UINT32 amount) = 0;
    virtual MM::BOOLEAN hasResources(MM::Instance * i,
                                     MM::Node * n,
                                     MM::UINT32 amount) = 0;
    
  public:
    virtual MM::VOID toString(MM::String * buf, MM::Name * name);
  };
}

#endif /* defined(__mm__NodeBehavior__) */
